#include "playground_scene.h"
#include "z64cutscene.h"
#include "z64cutscene_commands.h"


/**
 * Header Child Day (Default)
*/
SceneCmd playground_scene_header00[] = {
    SCENE_CMD_COL_HEADER(&playground_scene_collisionHeader),
    SCENE_CMD_ROOM_LIST(1, playground_scene_roomList),
    SCENE_CMD_SOUND_SETTINGS(0x00, 0x00, NA_BGM_FIELD_LOGIC),
    SCENE_CMD_MISC_SETTINGS(0x00, 0x00),
    SCENE_CMD_SPECIAL_FILES(0x00, OBJECT_GAMEPLAY_FIELD_KEEP),
    SCENE_CMD_SKYBOX_SETTINGS(0x01, 0x00, LIGHT_MODE_TIME),
    SCENE_CMD_ENV_LIGHT_SETTINGS(4, playground_scene_header00_lightSettings),
    SCENE_CMD_ENTRANCE_LIST(playground_scene_header00_entranceList),
    SCENE_CMD_SPAWN_LIST(1, playground_scene_header00_playerEntryList),
    SCENE_CMD_CUTSCENE_DATA(playground_introCS),
    SCENE_CMD_END(),
};

RomFile playground_scene_roomList[] = {
    { (uintptr_t)_playground_room_0SegmentRomStart, (uintptr_t)_playground_room_0SegmentRomEnd },
};

ActorEntry playground_scene_header00_playerEntryList[] = {
    // Link / Spawn point
    {
        /* Actor ID   */ ACTOR_PLAYER,
        /* Position   */ { -240, -120, 250 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(155.001), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0FFF
    },
};

Spawn playground_scene_header00_entranceList[] = {
    // { Spawn Actor List Index, Room Index }
    { 0, 0 },
};

EnvLightSettings playground_scene_header00_lightSettings[4] = {
    // Dawn Lighting
    {
        {    70,    45,    57 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {   180,   154,   138 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    20,    20,    60 },   // Diffuse1 Color
        {   140,   120,   100 },   // Fog Color
        ((1 << 10) | 993),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
    // Day Lighting
    {
        {   105,    90,    90 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {   255,   255,   240 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    50,    50,    90 },   // Diffuse1 Color
        {   100,   100,   120 },   // Fog Color
        ((1 << 10) | 996),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
    // Dusk Lighting
    {
        {   120,    90,     0 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {   250,   135,    50 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    30,    30,    60 },   // Diffuse1 Color
        {   120,    70,    50 },   // Fog Color
        ((1 << 10) | 995),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
    // Night Lighting
    {
        {    40,    70,   100 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {    20,    20,    35 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    50,    50,   100 },   // Diffuse1 Color
        {     0,     0,    30 },   // Fog Color
        ((1 << 10) | 992),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
};

CutsceneData playground_introCS[] = {
    CS_BEGIN_CUTSCENE(2, 152),
        CS_CAM_EYE_SPLINE(0, 151),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, 56, 0, 0, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, 112, 0, -50, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, -232, -80, 104, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, -236, -90, 154, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, -60, -25, 9, 0),
            CS_CAM_POINT(CS_CAM_STOP, 0, 0, 0.0f, 0, 0, 0, 0),
        CS_CAM_AT_SPLINE(0, 180),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, 56, 0, -56, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, 112, 0, -106, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, -232, -80, 160, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, -236, -90, 210, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, -114, -25, 24, 0),
            CS_CAM_POINT(CS_CAM_STOP, 0, 0, 0.0f, 0, 0, 0, 0),
    CS_END(),
};

CollisionHeader playground_scene_collisionHeader = {
    { -300, -170, -620 },
    { 300, 100, 300 },
    ARRAY_COUNT(playground_scene_vertices), playground_scene_vertices,
    ARRAY_COUNT(playground_scene_polygons), playground_scene_polygons,
    playground_scene_polygonTypes,
    NULL,
    0, NULL
};

SurfaceType playground_scene_polygonTypes[1] = {
    { SURFACETYPE0(0, 0, 0x00, 0, 0x00, 0x00, 0, 0), SURFACETYPE1(0x00, 0x00, 0, 0, 0, 0, 0, 0) },
};

Vec3s playground_scene_vertices[34] = {
    {   -300,   -170,   -188 },
    {   -300,   -120,    -58 },
    {      9,   -120,   -131 },
    {    140,   -120,   -300 },
    {    -83,   -170,   -300 },
    {   -159,   -170,   -203 },
    {   -300,   -170,   -300 },
    {    227,   -120,    300 },
    {    163,   -120,    181 },
    {    127,    -80,    241 },
    {    166,    -80,    300 },
    {     50,    -87,    221 },
    {     14,    -80,    300 },
    {    140,   -120,   -500 },
    {    -83,   -130,   -500 },
    {   -300,   -130,   -500 },
    {    300,   -120,    300 },
    {    300,   -120,   -500 },
    {   -300,   -120,    300 },
    {    -71,   -120,    300 },
    {     38,   -120,    123 },
    {    300,   -120,   -620 },
    {   -300,   -130,   -620 },
    {   -300,    100,    -58 },
    {   -300,    100,    300 },
    {   -300,     50,   -188 },
    {    300,    100,    300 },
    {    300,    100,   -620 },
    {   -300,   -170,   -298 },
    {   -300,     50,   -298 },
    {   -300,   -130,   -498 },
    {   -300,     90,   -498 },
    {   -300,   -130,   -618 },
    {   -300,     90,   -618 },
};

CollisionPoly playground_scene_polygons[45] = {
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(-0.08437332510948181), COLPOLY_SNORMAL(0.9295682907104492), COLPOLY_SNORMAL(-0.358864963054657) }, 65 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(3), { COLPOLY_SNORMAL(-0.2159271389245987), COLPOLY_SNORMAL(0.9619287848472595), COLPOLY_SNORMAL(-0.1675369143486023) }, 95 },
    { 0, COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(-0.051900167018175125), COLPOLY_SNORMAL(0.872877836227417), COLPOLY_SNORMAL(-0.4851708710193634) }, 42 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(-0.2137947380542755), COLPOLY_SNORMAL(0.9621893167495728), COLPOLY_SNORMAL(-0.16877087950706482) }, 95 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(4), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 170 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(6), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 170 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(9), { COLPOLY_SNORMAL(0.48815563321113586), COLPOLY_SNORMAL(0.8317887187004089), COLPOLY_SNORMAL(-0.2642567455768585) }, 68 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(9, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(10), { COLPOLY_SNORMAL(0.5175948739051819), COLPOLY_SNORMAL(0.7814341187477112), COLPOLY_SNORMAL(-0.3485059142112732) }, 81 },
    { 0, COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX(10, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(9), { COLPOLY_SNORMAL(-0.1155778169631958), COLPOLY_SNORMAL(0.9902452230453491), COLPOLY_SNORMAL(0.07782071083784103) }, 75 },
    { 0, COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX(12, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(10), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(0.9956486225128174), COLPOLY_SNORMAL(-0.09318802505731583) }, 108 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(3, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(13), { COLPOLY_SNORMAL(-0.21902284026145935), COLPOLY_SNORMAL(0.9757197499275208), COLPOLY_SNORMAL(7.366479337633791e-08) }, 148 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(14), { COLPOLY_SNORMAL(-0.043980199843645096), COLPOLY_SNORMAL(0.9796318411827087), COLPOLY_SNORMAL(0.1959264725446701) }, 222 },
    { 0, COLPOLY_VTX(6, COLPOLY_IGNORE_NONE), COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(14), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(0.9805806875228882), COLPOLY_SNORMAL(0.19611620903015137) }, 226 },
    { 0, COLPOLY_VTX(6, COLPOLY_IGNORE_NONE), COLPOLY_VTX(14, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(15), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(0.9805806875228882), COLPOLY_SNORMAL(0.19611620903015137) }, 226 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(16, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(17), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(17, COLPOLY_IGNORE_NONE), COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(3), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(18), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(17, COLPOLY_IGNORE_NONE), COLPOLY_VTX(3, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(17), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(18, COLPOLY_IGNORE_NONE), COLPOLY_VTX(19, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(20), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(20, COLPOLY_IGNORE_NONE), COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(17), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(17, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(18), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(17, COLPOLY_IGNORE_NONE), COLPOLY_VTX(18, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(20), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX(17, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(21), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(7.549790126404332e-08) }, 120 },
    { 0, COLPOLY_VTX(22, COLPOLY_IGNORE_NONE), COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(21), { COLPOLY_SNORMAL(-0.016664352267980576), COLPOLY_SNORMAL(0.9998611211776733), COLPOLY_SNORMAL(7.54874136532635e-08) }, 125 },
    { 0, COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX(14, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(13), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-7.549790126404332e-08), COLPOLY_SNORMAL(1.0) }, 500 },
    { 0, COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(21), { COLPOLY_SNORMAL(-0.022720851004123688), COLPOLY_SNORMAL(0.999281644821167), COLPOLY_SNORMAL(-0.030330710113048553) }, 108 },
    { 0, COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX(20, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(9), { COLPOLY_SNORMAL(0.2133108526468277), COLPOLY_SNORMAL(0.8662521243095398), COLPOLY_SNORMAL(-0.4517807066440582) }, 151 },
    { 0, COLPOLY_VTX(20, COLPOLY_IGNORE_NONE), COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(9), { COLPOLY_SNORMAL(-0.007905046455562115), COLPOLY_SNORMAL(0.9491875171661377), COLPOLY_SNORMAL(-0.31461194157600403) }, 153 },
    { 0, COLPOLY_VTX(20, COLPOLY_IGNORE_NONE), COLPOLY_VTX(19, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(11), { COLPOLY_SNORMAL(-0.4016192555427551), COLPOLY_SNORMAL(0.8816837072372437), COLPOLY_SNORMAL(-0.24766090512275696) }, 152 },
    { 0, COLPOLY_VTX(19, COLPOLY_IGNORE_NONE), COLPOLY_VTX(12, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(11), { COLPOLY_SNORMAL(-0.4109041094779968), COLPOLY_SNORMAL(0.8721033334732056), COLPOLY_SNORMAL(-0.2656944692134857) }, 155 },
    { 0, COLPOLY_VTX(18, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(23), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766771163268e-08), COLPOLY_SNORMAL(-2.6926461650373778e-15) }, 300 },
    { 0, COLPOLY_VTX(18, COLPOLY_IGNORE_NONE), COLPOLY_VTX(23, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(24), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766771163268e-08), COLPOLY_SNORMAL(-2.6926461650373778e-15) }, 300 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(23, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(1), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766771163268e-08), COLPOLY_SNORMAL(-3.33452518930244e-08) }, 300 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(25, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(23), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766060620532e-08), COLPOLY_SNORMAL(-3.33452518930244e-08) }, 300 },
    { 0, COLPOLY_VTX(18, COLPOLY_IGNORE_NONE), COLPOLY_VTX(24, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(26), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.1199770000303033e-08), COLPOLY_SNORMAL(-1.0) }, 300 },
    { 0, COLPOLY_VTX(18, COLPOLY_IGNORE_NONE), COLPOLY_VTX(26, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(16), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.1199761118518836e-08), COLPOLY_SNORMAL(-1.0) }, 300 },
    { 0, COLPOLY_VTX(16, COLPOLY_IGNORE_NONE), COLPOLY_VTX(26, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(27), { COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(0.0) }, 300 },
    { 0, COLPOLY_VTX(16, COLPOLY_IGNORE_NONE), COLPOLY_VTX(27, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(21), { COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(0.0) }, 300 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(28, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(25), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766771163268e-08), COLPOLY_SNORMAL(6.54549199265381e-15) }, 300 },
    { 0, COLPOLY_VTX(28, COLPOLY_IGNORE_NONE), COLPOLY_VTX(29, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(25), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766771163268e-08), COLPOLY_SNORMAL(6.54549199265381e-15) }, 300 },
    { 0, COLPOLY_VTX(28, COLPOLY_IGNORE_NONE), COLPOLY_VTX(30, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(29), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766771163268e-08), COLPOLY_SNORMAL(1.733953780558295e-08) }, 300 },
    { 0, COLPOLY_VTX(30, COLPOLY_IGNORE_NONE), COLPOLY_VTX(31, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(29), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669766060620532e-08), COLPOLY_SNORMAL(1.7339544911010307e-08) }, 300 },
    { 0, COLPOLY_VTX(30, COLPOLY_IGNORE_NONE), COLPOLY_VTX(32, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(31), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669765350077796e-08), COLPOLY_SNORMAL(6.545491145620863e-15) }, 300 },
    { 0, COLPOLY_VTX(32, COLPOLY_IGNORE_NONE), COLPOLY_VTX(33, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(31), { COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(8.669765350077796e-08), COLPOLY_SNORMAL(6.545491145620863e-15) }, 300 },
};

