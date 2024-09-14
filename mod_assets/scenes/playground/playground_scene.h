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
extern Vec3s playground_scene_vertices[23];
extern CollisionPoly playground_scene_polygons[30];
extern SceneCmd playground_room_0_header00[];
extern s16 playground_room_0_header00_objectList[];
extern ActorEntry playground_room_0_header00_actorList[];
extern Gfx playground_room_0_shapeHeader_entry_0_opaque[];
extern u64 playground_room_0_dl_grassGround_tex_ci8[];
extern u64 playground_room_0_dl_grassGround_tex_pal_rgba16[];
extern u64 playground_room_0_dl_stoneBorder_tex_ci4[];
extern u64 playground_room_0_dl_stoneBorder_tex_pal_rgba16[];
extern Vtx playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_cull[8];
extern Vtx playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_0[32];
extern Gfx playground_room_0_dl_Floor_mesh_layer_Opaque_tri_0[];
extern Vtx playground_room_0_dl_wall_0_mesh_layer_Opaque_vtx_cull[8];
extern Vtx playground_room_0_dl_wall_0_mesh_layer_Opaque_vtx_0[16];
extern Gfx playground_room_0_dl_wall_0_mesh_layer_Opaque_tri_0[];
extern Gfx mat_playground_room_0_dl_grass_layerOpaque[];
extern Gfx mat_playground_room_0_dl_walls_layerOpaque[];
extern Gfx playground_room_0_dl_Floor_mesh_layer_Opaque[];
extern Gfx playground_room_0_dl_wall_0_mesh_layer_Opaque[];
extern RoomShapeNormal playground_room_0_shapeHeader;
extern RoomShapeDListsEntry playground_room_0_shapeDListsEntry[1];

#endif
