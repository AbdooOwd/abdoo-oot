#ifndef Z_THE_DEV_H
#define Z_THE_DEV_H

#include "ultra64.h"
#include "global.h"

typedef struct the_dev {
	Actor actor;
	NpcInteractInfo interact_info;
	f32 time;
	f32 amplitude;
	f32 speed;
} the_dev;

#endif