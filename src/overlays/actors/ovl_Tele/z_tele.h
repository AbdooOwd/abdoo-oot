#ifndef Z_TELE_H
#define Z_TELE_H

#include "ultra64.h"
#include "global.h"

typedef struct Tele {
	Actor actor;
	NpcInteractInfo interact_info;
	f32 time;
	f32 scale_amplitude;
	f32 bounce_speed;
	Vec3f home_scale;
} Tele;

#endif