#include "playground_scene.h"


/**
 * Header Child Day (Default)
*/
#define LENGTH_PLAYGROUND_ROOM_0_HEADER00_OBJECTLIST 2
#define LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST 2
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
    OBJECT_SYOKUDAI,
};

ActorEntry playground_room_0_header00_actorList[LENGTH_PLAYGROUND_ROOM_0_HEADER00_ACTORLIST] = {
    // Custom Actor
    {
        /* Actor ID   */ ACTOR_NUL_BOX,
        /* Position   */ { 0, -70, -110 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Torch
    {
        /* Actor ID   */ ACTOR_OBJ_SYOKUDAI,
        /* Position   */ { 0, -120, 100 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },
};

RoomShapeNormal playground_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(playground_room_0_shapeDListsEntry),
    playground_room_0_shapeDListsEntry,
    playground_room_0_shapeDListsEntry + ARRAY_COUNT(playground_room_0_shapeDListsEntry)
};

RoomShapeDListsEntry playground_room_0_shapeDListsEntry[1] = {
    { playground_room_0_shapeHeader_entry_0_opaque, NULL }
};

Gfx playground_room_0_shapeHeader_entry_0_opaque[] = {
	gsSPDisplayList(playground_room_0_dl_Floor_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

u64 playground_room_0_dl_nakaniwa_room_0Tex_012618_rgba16_ci8[] = {
	0x0001020304050607, 0x08090a0b0c0d080e, 0x0f10111206101311, 0x1415030716170718, 0x191a1b030f1c1d1e, 0x1f0b202122232425, 0x11262728291d2a10, 0x2b10170f15152c05, 
	0x2d2e1117152b2f2b, 0x2f2b103031323334, 0x351d36372b1d270a, 0x102f2b1516100438, 0x3905263a1d102b15, 0x10073b3c3d3e3f27, 0x1b2b130310152620, 0x072f152727171940, 
	0x4115172026172727, 0x051517422b162706, 0x2b102a203527412a, 0x101d0f0726430427, 0x262706192920331d, 0x441713450f353533, 0x1011274617053511, 0x4727070f16353548, 
	0x262b1520201c3a49, 0x4a2b263a4b4c4d10, 0x15271736074e0508, 0x06442726152b2b06, 0x27421c41262d204f, 0x505152533a1e5403, 0x0406205510155657, 0x0507114658121010, 
	0x151c1037592b5a03, 0x051026390f50115b, 0x11202f265c07101d, 0x36390720113a1d26, 0x17075d273304265e, 0x172b152b1507265f, 0x2026600626070742, 0x1d61176254115d07, 
	0x27152703261c6302, 0x1127101c15051c1b, 0x5f09642015102b2a, 0x2b271c0426346544, 0x110f271117112620, 0x45050f6667050768, 0x696a6b271c6c2f1c, 0x6d07611b26116e27, 
	0x6517263a313a3b15, 0x0f0a2f2b10156f70, 0x71156d041d261c1c, 0x1127273504725b20, 0x11172f3a032b4915, 0x271c1c101d297374, 0x3f7527151e752a42, 0x422611102f761c36, 
	0x07277778191d2010, 0x111079271d421d15, 0x1d3a152631072726, 0x55270f1503171355, 0x20112e13111d1671, 0x562a14321b7a0f10, 0x446e07116e051d04, 0x62061d26041f1015, 
	0x3327190510071071, 0x7b7c7d7e617f0a80, 0x418182833f074d5c, 0x8401364a8517164d, 0x0707264a155d1c69, 0x863c87880f4f898a, 0x208b8c8d8e1c2a14, 0x6e26058b3b273507, 
	0x03261713142f2b33, 0x8f343c8c901f9191, 0x05928c938d102717, 0x2015206e26274d58, 0x1c40202076152742, 0x9495953e4e362011, 0x1596979867051116, 0x1b77262f31050303, 
	0x06095e042720275a, 0x1d1c0a1015260a27, 0x2637929926367604, 0x4406071535112720, 0x17969a409b6e0542, 0x5a9c9d2f9d272011, 0x072f719e1c20064f, 0x2649390516179f20, 
	0x17261602a02f3615, 0x2626755a26173b26, 0x1c291ca131010554, 0x1407052027352b11, 0x4d353517072b0710, 0x2f9d2917421d1e1d, 0x0f1c0f2615174207, 0x1d2b2736064f05a2, 
	0x4905072707271054, 0x265aa326061c0626, 0x399a63271c1d2b1d, 0x422a2720354a072a, 0x117617421517114a, 0x27119f111204445f, 0x2b4f27072b101d2b, 0x1c1d2a20a4a59f11, 
	0x27054f4a2b07179f, 0x13330508a6050726, 0x04410f2b27361410, 0x2b173620040f6543, 0x044ca74d1d270f11, 0x04337636270741a8, 0x11102f1d2b071516, 0x26a9040426556380, 
	0x0405440542275615, 0x1706aa272b291d17, 0x05262b5a0fab172d, 0x1d3a0f1d07262015, 0x0a1045ac151cad1d, 0x0f130205152b102a, 0x1517074d07260506, 0x760f06152a276e06, 
	0x17aeaf5126101117, 0x455c2b3c0bb0201c, 0x1d1c0520152b1b0f, 0x2a1d4d1510152b20, 0xb11504b20f1d4558, 0x4d1959b3b4b5468b, 0x01b65f1e171d2d11, 0x1c070fb72b07264c, 
	
};

u64 playground_room_0_dl_nakaniwa_room_0Tex_012618_rgba16_pal_rgba16[] = {
	0xa6e75d4b65553b81, 0x6553548b4c013b01, 0x5c538e1b4c438595, 0xaf9b9f9f86954387, 0x43474bc143895d0d, 0x4c0b3b414c4b4c07, 0xaead550b5dcb6511, 0x32413a8143c754c3, 
	0x54876d8df7f5cff1, 0x9f9b85934c474bc7, 0x4c8d298132c13281, 0x7dd955077e593201, 0x7e916dd39e6154cd, 0x648d548d4c875c91, 0x6e1554c75d4d5d47, 0x6d515bcd6ccd5b8d, 
	0x5d8b43c129c175d5, 0x54cb5c8d64d15d11, 0x4c11550d5cd17553, 0x6dd7549118c16d93, 0x5c8b7d536e515d87, 0x540754476c518e19, 0x4c0d5d0b29416e17, 0x64d32a0175d96dd1, 
	0x5dc73301658f4c83, 0xaea76d136c0d6c91, 0x7413540b85db7dd7, 0x19415cd36591640d, 0x84156c1165955b47, 0x42c143016551658d, 0x8ea17e5d6d0d8d9b, 0x7d95aedf9e198517, 
	0x7e558f9d86975c4d, 0xb6eb75976d11c7e7, 0x9edbae677ed77e15, 0xdfb395db8d1b7591, 0x86577613bf67a6db, 0x530d75936d4dbf69, 0xaf259f5d7e5b6d91, 0x6b4d4a418e994c8b, 
	0x7513cf718d9774d3, 0xb6a5654d434965cf, 0x85d976575d536493, 0x6e934bcb6d956d97, 0x644d6d5b6c4d96d7, 0xae5f8555648b4c4d, 
};

Vtx playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-300, -120, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -120, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -120, -300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-300, -120, -300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -120, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -120, 300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -120, -300}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {300, -120, -300}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_0[4] = {
	{{ {-300, -120, 300}, 0, {-1194, 2186}, {0, 127, 0, 255} }},
	{{ {300, -120, 300}, 0, {2186, 2186}, {0, 127, 0, 255} }},
	{{ {300, -120, -300}, 0, {2186, -1194}, {0, 127, 0, 255} }},
	{{ {-300, -120, -300}, 0, {-1194, -1194}, {0, 127, 0, 255} }},
};

Gfx playground_room_0_dl_Floor_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_playground_room_0_dl_floor_mat_layerOpaque[] = {
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, playground_room_0_dl_nakaniwa_room_0Tex_012618_rgba16_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 183),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, playground_room_0_dl_nakaniwa_room_0Tex_012618_rgba16_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx playground_room_0_dl_Floor_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(playground_room_0_dl_Floor_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_playground_room_0_dl_floor_mat_layerOpaque),
	gsSPDisplayList(playground_room_0_dl_Floor_mesh_layer_Opaque_tri_0),
	gsSPEndDisplayList(),
};

