#include "playground_scene.h"


/**
 * Header Child Day (Default)
*/
#define LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST 4
#define LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST 3
SceneCmd playground_room_0_header00[] = {
    SCENE_CMD_ROOM_SHAPE(&playground_room_0_shapeHeader),
    SCENE_CMD_ECHO_SETTINGS(0x00),
    SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(false, false),
    SCENE_CMD_TIME_SETTINGS(255, 255, 10),
    SCENE_CMD_OBJECT_LIST(LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST, playground_room_0_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST, playground_room_0_header00_actorList),
    SCENE_CMD_END(),
};

s16 playground_room_0_header00_objectList[LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST] = {
    OBJECT_NUL_BOX,
    OBJECT_TROLOLO,
    OBJECT_TELE,
    OBJECT_KANBAN,
};

ActorEntry playground_room_0_header00_actorList[LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST] = {
    // Square Signpost
    {
        /* Actor ID   */ ACTOR_EN_KANBAN,
        /* Position   */ { 70, -80, 270 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(180.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0001
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_THE_DEV,
        /* Position   */ { 250, -100, 190 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(270.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_TELE,
        /* Position   */ { 270, -110, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(180.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x00C0
    },
};

