#ifndef Z_CHECK_SPOT_H
#define Z_CHECK_SPOT_H

#include "ultra64.h"
#include "global.h"

typedef struct CheckSpot {
	Actor actor;
	f32 dist;
	NpcInteractInfo interact_info;
} CheckSpot;

#endif