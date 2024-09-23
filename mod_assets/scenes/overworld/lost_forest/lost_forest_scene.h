#ifndef LOST_FOREST_SCENE_H
#define LOST_FOREST_SCENE_H

#include "ultra64.h"
#include "macros.h"
#include "z64.h"


extern SceneCmd lost_forest_scene_header00[];
extern RomFile lost_forest_scene_roomList[];
extern u8 _lost_forest_room_0SegmentRomStart[];
extern u8 _lost_forest_room_0SegmentRomEnd[];
extern ActorEntry lost_forest_scene_header00_playerEntryList[];
extern Spawn lost_forest_scene_header00_entranceList[];
extern u16 lost_forest_scene_header00_exitList[1];
extern EnvLightSettings lost_forest_scene_header00_lightSettings[4];
extern Vec3s lost_forest_scene_header00_pathwayList00[];
extern Path lost_forest_scene_header00_pathway[1];
extern CutsceneData welcome_CS[];
extern CollisionHeader lost_forest_scene_collisionHeader;
extern WaterBox lost_forest_scene_waterBoxes[1];
extern SurfaceType lost_forest_scene_polygonTypes[2];
extern Vec3s lost_forest_scene_vertices[57];
extern CollisionPoly lost_forest_scene_polygons[87];
extern SceneCmd lost_forest_room_0_header00[];
extern s16 lost_forest_room_0_header00_objectList[];
extern ActorEntry lost_forest_room_0_header00_actorList[];
extern Gfx lost_forest_room_0_shapeHeader_entry_0_opaque[];
extern Gfx lost_forest_room_0_shapeHeader_entry_0_transparent[];
extern u64 lost_forest_room_0_dl_grassGround_tex_rgba16_ci8[];
extern u64 lost_forest_room_0_dl_grassGround_tex_rgba16_pal_rgba16[];
extern u64 lost_forest_room_0_dl_stoneBorder_tex_ci4_ci4[];
extern u64 lost_forest_room_0_dl_stoneBorder_tex_ci4_pal_rgba16[];
extern u64 lost_forest_room_0_dl_grassGround_wall_rgba16_rgba16[];
extern u64 lost_forest_room_0_dl_brown_rocky_rgba16_ci8[];
extern u64 lost_forest_room_0_dl_brown_rocky_rgba16_pal_rgba16[];
extern u64 lost_forest_room_0_dl_water_rgba16_ci8[];
extern u64 lost_forest_room_0_dl_water_rgba16_pal_rgba16[];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_cull[8];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_0[26];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque_tri_0[];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_1[83];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque_tri_1[];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_2[30];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque_tri_2[];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_3[8];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque_tri_3[];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_4[4];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque_tri_4[];
extern Vtx lost_forest_room_0_dl_floor_mesh_layer_Opaque_vtx_5[4];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque_tri_5[];
extern Vtx lost_forest_room_0_dl_waterbox_0_mesh_layer_Transparent_vtx_cull[8];
extern Vtx lost_forest_room_0_dl_waterbox_0_mesh_layer_Transparent_vtx_0[4];
extern Gfx lost_forest_room_0_dl_waterbox_0_mesh_layer_Transparent_tri_0[];
extern Gfx mat_lost_forest_room_0_dl_floor_mat_layerOpaque[];
extern Gfx mat_lost_forest_room_0_dl_walls_layerOpaque[];
extern Gfx mat_lost_forest_room_0_dl_grass_wall_layerOpaque[];
extern Gfx mat_lost_forest_room_0_dl_rocky_layerOpaque[];
extern Gfx mat_lost_forest_room_0_dl_black_layerOpaque[];
extern Gfx mat_lost_forest_room_0_dl_grass_exit_0_layerOpaque[];
extern Gfx mat_lost_forest_room_0_dl_oot_water_mat_layerTransparent[];
extern Gfx lost_forest_room_0_dl_floor_mesh_layer_Opaque[];
extern Gfx lost_forest_room_0_dl_waterbox_0_mesh_layer_Transparent[];
extern RoomShapeNormal lost_forest_room_0_shapeHeader;
extern RoomShapeDListsEntry lost_forest_room_0_shapeDListsEntry[1];

#endif
