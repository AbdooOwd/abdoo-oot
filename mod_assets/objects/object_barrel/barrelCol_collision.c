#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "barrelCol_collision.h"

CollisionHeader barrelCol_collisionHeader = {
    { -2700, 0, -2700 },
    { 2700, 6000, 2700 },
    ARRAY_COUNT(barrelCol_vertices), barrelCol_vertices,
    ARRAY_COUNT(barrelCol_polygons), barrelCol_polygons,
    barrelCol_polygonTypes,
    NULL,
    0, NULL
};

SurfaceType barrelCol_polygonTypes[1] = {
    { SURFACETYPE0(0, 0, 0x00, 0, 0x00, 0x00, 0, 0), SURFACETYPE1(0x0A, 0x00, 0, 0, 0, 0, 0, 0) },
};

Vec3s barrelCol_vertices[16] = {
    {      0,      0,  -2700 },
    {      0,   6000,  -2700 },
    {   1909,   6000,  -1909 },
    {   1909,      0,  -1909 },
    {   2700,   6000,      0 },
    {   2700,      0,      0 },
    {   1909,   6000,   1909 },
    {   1909,      0,   1909 },
    {      0,   6000,   2700 },
    {      0,      0,   2700 },
    {  -1909,   6000,   1909 },
    {  -1909,      0,   1909 },
    {  -2700,   6000,      0 },
    {  -2700,      0,      0 },
    {  -1909,   6000,  -1909 },
    {  -1909,      0,  -1909 },
};

CollisionPoly barrelCol_polygons[28] = {
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(0.3826834261417389), COLPOLY_SNORMAL(-3.6711675477363315e-08), COLPOLY_SNORMAL(-0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(3), { COLPOLY_SNORMAL(0.3826834261417389), COLPOLY_SNORMAL(-3.6711675477363315e-08), COLPOLY_SNORMAL(-0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(3, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(4), { COLPOLY_SNORMAL(0.9238794445991516), COLPOLY_SNORMAL(-1.5206476078333253e-08), COLPOLY_SNORMAL(-0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(3, COLPOLY_IGNORE_NONE), COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(5), { COLPOLY_SNORMAL(0.9238795042037964), COLPOLY_SNORMAL(-1.672762550697371e-08), COLPOLY_SNORMAL(-0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(6), { COLPOLY_SNORMAL(0.9238794445991516), COLPOLY_SNORMAL(1.672762550697371e-08), COLPOLY_SNORMAL(0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX(6, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(7), { COLPOLY_SNORMAL(0.9238794445991516), COLPOLY_SNORMAL(1.5206476078333253e-08), COLPOLY_SNORMAL(0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(6, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(8), { COLPOLY_SNORMAL(0.3826834261417389), COLPOLY_SNORMAL(3.6711675477363315e-08), COLPOLY_SNORMAL(0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(9), { COLPOLY_SNORMAL(0.3826834261417389), COLPOLY_SNORMAL(3.6711675477363315e-08), COLPOLY_SNORMAL(0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(9, COLPOLY_IGNORE_NONE), COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(10), { COLPOLY_SNORMAL(-0.3826834261417389), COLPOLY_SNORMAL(3.6711675477363315e-08), COLPOLY_SNORMAL(0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(9, COLPOLY_IGNORE_NONE), COLPOLY_VTX(10, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(11), { COLPOLY_SNORMAL(-0.3826834261417389), COLPOLY_SNORMAL(3.6711675477363315e-08), COLPOLY_SNORMAL(0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX(10, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(12), { COLPOLY_SNORMAL(-0.9238794445991516), COLPOLY_SNORMAL(1.5206476078333253e-08), COLPOLY_SNORMAL(0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX(12, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(13), { COLPOLY_SNORMAL(-0.9238794445991516), COLPOLY_SNORMAL(1.672762550697371e-08), COLPOLY_SNORMAL(0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(1), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 59536 },
    { 0, COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX(14, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(12), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 59536 },
    { 0, COLPOLY_VTX(12, COLPOLY_IGNORE_NONE), COLPOLY_VTX(10, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(8), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 59536 },
    { 0, COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX(6, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(4), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 59536 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(12), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 59536 },
    { 0, COLPOLY_VTX(12, COLPOLY_IGNORE_NONE), COLPOLY_VTX(8, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(4), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 59536 },
    { 0, COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX(12, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(14), { COLPOLY_SNORMAL(-0.9238794445991516), COLPOLY_SNORMAL(-1.672762550697371e-08), COLPOLY_SNORMAL(-0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX(14, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(15), { COLPOLY_SNORMAL(-0.9238795042037964), COLPOLY_SNORMAL(-1.5206476078333253e-08), COLPOLY_SNORMAL(-0.3826834261417389) }, 63042 },
    { 0, COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX(14, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(1), { COLPOLY_SNORMAL(-0.3826834261417389), COLPOLY_SNORMAL(-3.6711675477363315e-08), COLPOLY_SNORMAL(-0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(0), { COLPOLY_SNORMAL(-0.3826834261417389), COLPOLY_SNORMAL(-3.6711675477363315e-08), COLPOLY_SNORMAL(-0.9238794445991516) }, 63042 },
    { 0, COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(3), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(4.371134920688746e-08) }, 0 },
    { 0, COLPOLY_VTX(3, COLPOLY_IGNORE_NONE), COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(7), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(4.371140605030632e-08) }, 0 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(9, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(11), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(4.371142026116104e-08) }, 0 },
    { 0, COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX(13, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(15), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(4.371140605030632e-08) }, 0 },
    { 0, COLPOLY_VTX(15, COLPOLY_IGNORE_NONE), COLPOLY_VTX(3, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(7), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(4.371140605030632e-08) }, 0 },
    { 0, COLPOLY_VTX(7, COLPOLY_IGNORE_NONE), COLPOLY_VTX(11, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(15), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(-1.0), COLPOLY_SNORMAL(4.371140605030632e-08) }, 0 },
};

