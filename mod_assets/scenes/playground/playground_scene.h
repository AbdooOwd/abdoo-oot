#ifndef PLAYGROUND_SCENE_H
#define PLAYGROUND_SCENE_H

#include "ultra64.h"
#include "macros.h"
#include "z64.h"


extern SceneCmd playground_scene_header00[];
extern RomFile playground_scene_roomList[];
extern u8 _playground_room_0SegmentRomStart[];
extern u8 _playground_room_0SegmentRomEnd[];
extern ActorEntry playground_scene_header00_playerEntryList[];
extern Spawn playground_scene_header00_entranceList[];
extern EnvLightSettings playground_scene_header00_lightSettings[4];
extern CollisionHeader playground_scene_collisionHeader;
extern SurfaceType playground_scene_polygonTypes[1];
extern Vec3s playground_scene_vertices[4];
extern CollisionPoly playground_scene_polygons[2];
extern SceneCmd playground_room_0_header00[];
extern s16 playground_room_0_header00_objectList[];
extern ActorEntry playground_room_0_header00_actorList[];
extern Gfx playground_room_0_shapeHeader_entry_0_opaque[];
extern u64 playground_room_0_dl_nakaniwa_room_0Tex_012618_rgba16_ci8[];
extern u64 playground_room_0_dl_nakaniwa_room_0Tex_012618_rgba16_pal_rgba16[];
extern Vtx playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_cull[8];
extern Vtx playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_0[4];
extern Gfx playground_room_0_dl_Floor_mesh_layer_Opaque_tri_0[];
extern Gfx mat_playground_room_0_dl_floor_mat_layerOpaque[];
extern Gfx playground_room_0_dl_Floor_mesh_layer_Opaque[];
extern RoomShapeNormal playground_room_0_shapeHeader;
extern RoomShapeDListsEntry playground_room_0_shapeDListsEntry[1];

#endif
