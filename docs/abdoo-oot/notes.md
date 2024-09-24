# Notes (cuz i'm really smart, legit)

-	Some versions of binutils-ld have a bug that make linking
	**EXTREMELY** slow. Here is the [link](https://discord.com/channels/688807550715560050/688851317593997489/1120461394207318146)
	on how to get a "better" binutils ld. (it is pinned in `#oot-decomp` in **ZeldaRET** Discord Server).

-	`ActorProfile` was previously `ActorInit`.
	-	When declaring an actor's InitVars/Profile. It **MUST** be called
		`ActorName_Profile` *(also based on the name you gave to its define)*.

-	Any `getNextTalkingId` function for an NPC is run every frame.

-	Let's forget about the actor's local `textId`. Our savior is `msgCtx`'s `textId`.

-	To attach a text ID to a sign post (`EN_KANBAN` actor), the text ID must be greater
	than `0x300`. And the sign-post's params must be the text ID that you want to display
	decreased by `0x300`.
	For example, if I want to display my message with text ID of `0x0302`, I must attach
	`0x0002` to the sign's params. *(**NOTE:** `0x0000` is the `X` message)*.

-	In HackerOoT, open map select by pressing [L] + [R] + [Z] ***(IN ORDER!!!)***

-	Sometimes, when adding textures, you must remove them from `extracted/` first.

-	To make something float:
	```py
	import math

	time = 0
	amplitude = 30  # The maximum distance the object moves up and down
	speed = 0.05  # How fast the object floats

	def update():
	    # Calculate the new y position using the sine wave
	    obj.y = amplitude * math.sin(time)
	
	    # Increment time to animate the floating
	    time += speed
	```

-	If I keep [Z] button pressed while displaying a textbox, and that textbox
	has a speaker switch, when the textbox closes; the camera stays stuck
	in `LookAt` camera mode *(mode used when switching talkers)*.

-	Gotta set `PlayState`'s `nextEntranceId` so you switch scenes 
	*(Or use my macro `SET_NEXt_ENTRANCE`)*.

-	29 test entrances.

-	`OBJ_TSUBO` *(ie. pot)* can only be used with `gameplay_dangeon_keep` alias setting
	the scene as a dungeon.

-	`Actor_OfferCarry` can be used to pick up a prop.

-	`ACTOR_FLAG_23` means it's a prop actor that can only thrown.
	Cannot be dropped. Only throw.

-	`ACTOR_FLAG_29` is a flag I added for prop actors that can only
	be dropped/put down. Cannot be thrown.

-	When using `Math_SmoothStepTo`, setting the `minStep` to `0` might save
	you a BUNCH of time *(it sometimes causes the transition to go **COOCOO**)*.

-	Default audio volume *(I think)* is `0x7F`.