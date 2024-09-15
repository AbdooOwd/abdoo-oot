# How to Add a New Object

# 1. The Mesh + Collision

Go to Blender, have that Fast64 up and running, then make something.
Your materials should be F3D materials *(Fast3D)*. I recommend using
only planes or use the least amount possible of vertices. Remember that
the game you're building is supposed to run on a Nintendo 64.
In Fast64, you'll have 2 tabs in "OoT": **"OoT DL Exporter"** and **"OoT Collision Exporter"**
*(make sure to export them to the same location)*.

When you're done, export it to whever you want. Don't forget to export the collision!

You should now have a .c and .h file for your mesh and another .c .h duo for your collisions.

# 2. Adding the Object to the Game Files

## 2.1 Adding to Object Table

Go to `object_table.h` and add your object, duh.

**EXAMPLE:** Let's Make a `computer` object!
```c
DEFINE_OBJECT(object_computer, OBJECT_COMPUTER)
```
The first argument should match our object's name in the game files.

## 2.2 Adding to Spec

Go to `spec` and copy a previous actor's "code".

**EXAMPLE:** Our object; `computer`.
```
beginseg
    name "object_computer"
    compress
    romalign 0x1000
    include "$(BUILD_DIR)/assets/objects/object_computer/computer.o"
    number 6
endseg
```
> That last `.o` file should the same name as the `.c` file of your object.