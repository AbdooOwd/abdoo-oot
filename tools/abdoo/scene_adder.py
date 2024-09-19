import sys

# Process:
# - Add Scene to scene_table (done by Fast64)
# - Add Scene to scene selection (debug)
# - Add Scene's entrance to entrance_table
# - Add Scene to spec (done by Fast64)
# [WARNING] All of the "done by Fast64" is only done if you haven't checked "custom path"

entrance_table_path = "include/tables/entrance_table.h"
scene_table_path = "include/tables/scene_table.h"
spec_path = "spec"
z_select_path = "src/overlays/gamestates/ovl_select/z_select.h"

sScenesArray = "static SceneSelectEntry sScenes[] = {"	# hardcoded, used to detect where the array is
titleScreenZSelect = "{ \"Title Screen\", (void*)MapSelect_LoadTitle, 0 },"

def addEntranceTable(scene_name: str) -> None:
	with open(entrance_table_path, 'a') as file:
		# file.write("\n\n/* PYTHON GENERATED CODE AHEAD */\n")
		file.write("\n\n")
		for i in range(4):
			file.write(f"DEFINE_ENTRANCE(ENTR_{scene_name.upper()}_0_{i}, SCENE_{scene_name.upper()}, 0, false, true, TRANS_TYPE_FADE_WHITE, TRANS_TYPE_FADE_WHITE)\n")
	print("- Added scene entrances to entrance table!")

def addSpec(scene_name: str, scene_path: str, room_count: int) -> None:
	print("- Adding scene to spec")
	print(" > Adding scene objects to spec...")
	# Add Scene
	removed_mod_dir = scene_path.replace("mod_assets/scenes", "")
	with open(spec_path, 'a') as file:
		file.write(
			 "\nbeginseg\n"
			f"\tname \"{scene_name}_scene\"\n"
			 "\tcompress\n"
			 "\tromalign 0x1000\n"
    		f"\tinclude \"$(BUILD_DIR)/assets/scenes/{removed_mod_dir}/{scene_name}/{scene_name}_scene.o\"\n"
    		 "\tnumber 2\n"
			   "endseg\n"
			)
	
	print(" > Adding room(s) objects to spec")
	# Add rooms
	for i in range(room_count):
		with open(spec_path, 'a') as file:
			file.write(
				 "\nbeginseg\n"
    			f"\tname \"{scene_name}_room_{i}\"\n"
    			 "\tcompress\n"
    			 "\tromalign 0x1000\n"
    			f"\tinclude \"$(BUILD_DIR)/assets/scenes/{removed_mod_dir}/{scene_name}/{scene_name}_room_{i}.o\"\n"
    			 "\tnumber 3\n"
				   "endseg\n"
				)
	print("- Added scene to spec!")

def addSceneTable(scene_name: str) -> None:
	with open(scene_table_path, 'a') as file:
		file.write(f"\nDEFINE_SCENE({scene_name}_scene, none, SCENE_{scene_name.upper()}, SDC_DEFAULT, 0, 0)")
	print("- Added scene to scene table!")

def addSceneSelection(scene_name: str) -> None:
	print("- Adding scene to z_select (MapSelect)...")
	with open(z_select_path, "r") as file:
		content = file.readlines()

	for i, line in enumerate(content):
		if titleScreenZSelect in line:
			content.insert(i + 1, "\t{ \"" + scene_name.capitalize().replace("_", "") + "\", MapSelect_LoadGame, ENTR_" + scene_name.upper() + "_0 },\n")
			break
	
	with open(z_select_path, "w") as file:
		file.writelines(content)
	
	print("- Added scene to z_select!")

def main():
	argc = len(sys.argv)

	if argc < 2 or argc != 4:
		print(f"Not enough arguments! Usage: {sys.argv[0]} <scene name> <scene path> <room count>")
		quit(-1)

	addEntranceTable(sys.argv[1])
	addSceneSelection(sys.argv[1])

	if argc >= 4:
		addSceneTable(sys.argv[1])
		addSpec(sys.argv[1], sys.argv[2], int(sys.argv[3]))


if __name__ == "__main__":
	main()