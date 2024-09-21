import sys
import os


template_path = "tools/abdoo/actor"
overlays_source_dir = "src/overlays/actors/"
actor_table_path = "include/tables/actor_table.h"
spec_path = "spec"


# source editing funcs

def fillSource(actor_name: str, file_path: str):

	# add C source
	with open(template_path + '.c', 'r') as file:
		temp = file.read()
	
	with open(file_path + '.c', 'w') as file:
		file.write(
			temp.replace('ACTORFILLER', actor_name.replace("_", ""))
				.replace('ACTOR_FILLER', actor_name)
				.replace('ACTORUPPER', actor_name.upper())
				.replace('ACTORLOWER', actor_name.lower())
		)
	
	# add Header source
	with open(template_path + '.h', 'r') as file:
		temp = file.read()
	
	with open(file_path + '.h', 'w') as file:
		file.write(temp.replace('ACTORFILLER', actor_name).replace('ACTORUPPER', actor_name.upper()))


def addTable(actor_name: str) -> None:
	print("Adding actor to Actor Table...")

	add_this = f"DEFINE_ACTOR({actor_name}, ACTOR_{actor_name.upper()}, ACTOROVL_ALLOC_NORMAL, \"{actor_name}\")"

	with open(actor_table_path, 'r') as file:
		if file.read().find(add_this) != -1:
			print(" > Actor already in actor table!")
			# quit(-42)
			return

	with open(actor_table_path, 'a') as file:
		file.write(
			"\n\t\t\t " + add_this
		)
	
	print("Added actor to Actor Table!")

def addSource(actor_name: str) -> None:
	print("Creating C source files...")
	el_path = os.path.join(overlays_source_dir, f'ovl_{actor_name}')

	if os.path.exists(el_path):
		print(" > Directory already exists!")
		# quit(-1)
	
	if os.path.exists(os.path.join(el_path, f'z_{actor_name.lower()}.c')):
		print(f" > z_{actor_name.lower()}.c already exists!")
		# quit(-2)
		return
	
	if os.path.exists(os.path.join(el_path, f'z_{actor_name.lower()}.h')):
		print(f" > z_{actor_name.lower()}.h already exists!")
		# quit(-3)
		return

	os.mkdir(os.path.join(overlays_source_dir, f'ovl_{actor_name}'))
	print(f"Created directory 'ovl_{actor_name}'")

	os.mknod(os.path.join(el_path, f'z_{actor_name.lower()}.h'))
	print(f"Created source file: 'z_{actor_name.lower()}.h'")

	os.mknod(os.path.join(el_path, f'z_{actor_name.lower()}.c'))
	print(f"Created source file: 'z_{actor_name.lower()}.c'")

	fillSource(actor_name, os.path.join(el_path, f'z_{actor_name.lower()}'))

	print("C source files creation done!")

def addSpec(actor_name: str) -> None:
	print("Adding actor to spec...")

	with open(spec_path, 'r') as file:
		content = file.readlines()
	
	for i, line in enumerate(content):
		# TODO: fix spec not correctly checking
		if line.lower().count(f"name \"ovl_{actor_name}\"".lower()) != 0:
			print(f" > Actor already exists in 'spec'!")
			return
		
		if "/* ACTORS FOR PYTHON */" in line:
			content.insert(i + 1,
				"\nbeginseg\n"
    			f"\tname \"ovl_{actor_name}\"\n"
    			"\tcompress\n"
    			f"\tinclude \"$(BUILD_DIR)/src/overlays/actors/ovl_{actor_name}/z_{actor_name.lower()}.o\"\n"
    			f"\tinclude \"$(BUILD_DIR)/src/overlays/actors/ovl_{actor_name}/ovl_{actor_name}_reloc.o\"\n"
				"endseg\n\n" 
			)

			break

	with open(spec_path, 'w') as file:
		file.writelines(content)
	
	print("Added actor to spec!")

def main():
	argc = len(sys.argv)

	if argc < 2:
		print(f"Not enough arguments! Usage: {sys.argv[0]} <actor name>")
		return
	
	addSpec(sys.argv[1])
	addTable(sys.argv[1])
	addSource(sys.argv[1])


if __name__ == "__main__":
	main()