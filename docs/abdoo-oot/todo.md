# Abdoo-OoT ToDo List

-	Code a Python script to ***correctly*** add a scene to 
	the game (Fast64 does it, but without the "entrances" thing) [X]

-	Put in a function the code to make the camera look 
	at an NPC when talking to him [X]
	
	-	Use this function to make the camera 
	face Link when meeting a trigger:

		-	Use the function [X] *(it's `Message_switchSpeaker`)*
		-	Code a trigger like `BOX_BREAK` [X]

-	Add whd as a boss [ ]
-	Add Abi Boss (with water/gaz pipe) [ ]
	-	Have the boss fight start with him askin if I did X
	then we have 2 options: yes (liar), no (fight)

- 	Figure out how to make cutscenes [ ]
-	Make intro cutscene [ ]
	-	**Scenario 1:** Abdoo is chillin' in his flat. Until his N64 bugs
		and transports him into ZeldaOoT.
	-	**Scenario 2:** The world is about to try an experiment, but this experiment
		made that a few people in the world got teleported into ZeldaOoT.
		Of course, Abdoo's one of them.

-	After checking the TV, Abdoo is teleported into OoT.

-	Learn about OoT's filesystem.
-	Make an Audio driver so it can play audio files.
-	Play music in-game.

-	Make infiltration/sneaky mission [ ]
-	Make a barrel in which Link can hide [X]
	-	Make barrel be actor instead of DynaPoly [ ]
	-	Make barrel use a CollisionCylinder [ ]

-	Understand the code for the pot, kibako and barrel [ ]

-	**Patrol Guard**
	-	When Link is hidden but moving, make `camera->at` the guard's position.
		Start a timer, then once finished, make guard patrol back and reset `camera->at`.
	-	Make good Camera Effects *(same as I wanted, but less "junky" and "broken")*.

-	In Lowden village, the village is under control of "bad-guy"'s control.
	The village look almost abandoned in the night, and almost dead (but still with people)
	in the day. Kind of like France on Algeria.
	-	Make a big "surveillance post".
	-	Add some "barbelet".
	-	Add some sharp stuff that is supposed to keep
		the villagers in place.

## Funny

-	Have a time in the scenario where there's a fake death screen.
	The music plays normally, Link falls on the ground. Then suddenly: the music stops,
	Navi might tell us something or Link notices something then wakes up.
	It would be both funny and *"epok"*.