#include "playground_scene.h"


RoomShapeNormal playground_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(playground_room_0_shapeDListsEntry),
    playground_room_0_shapeDListsEntry,
    playground_room_0_shapeDListsEntry + ARRAY_COUNT(playground_room_0_shapeDListsEntry)
};

RoomShapeDListsEntry playground_room_0_shapeDListsEntry[1] = {
    { playground_room_0_shapeHeader_entry_0_opaque, NULL }
};

