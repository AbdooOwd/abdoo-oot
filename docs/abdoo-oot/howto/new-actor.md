# How to Add a New Actor (from scratch)

Actors are basically objects in the game. But actors are themselves basedo on objects.
**Objects** are the assets: the 3D model and the textures. **Actors** are the things 
has a behaviour *(code)* and uses an **object** to "draw itself" *(I hope this made sense)*.

# 1. File structure

Actors are stored in `src/overlays/actors/`. Each actor has its own folder *(e.g `ovl_Arrow_Light`)*.
A normal actor's folder contains two things: a C file and a header file *(`.h` file)*.
If you don't know what that is, please learn some C.

# 2. Define "Life Cycle" functions

Name given by [Kenton M](https://www.youtube.com/@kentonm) *(best OoT modder btw)*, ***"Life Cycle"***
functions are functions that are needed by their actor. Each actor has at least 4 of these
functions *(assuming our actor is `XD`)*:
-	`XB_Init`: For Initialization.
-	`XB_Destroy`: When destroyed/killed *(deleted)*.
-	`XB_Update`: Runs every frame *(20 times a second)*.
-	`XB_Draw`: idk man.

# 3. Associate an object to the Actor

An actor is something that uses an object to do "stuff".
The object is the mesh/textures.
So, we'll need an object!

Just make an object *([psssttt, over here](./new-object.md))*.