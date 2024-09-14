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