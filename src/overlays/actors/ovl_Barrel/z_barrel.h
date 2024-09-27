#ifndef Z_BARREL_H
#define Z_BARREL_H

#include "ultra64.h"
#include "global.h"

struct Barrel;

typedef void (*BarrelActionFunc)(struct Barrel*, PlayState*);

typedef struct Barrel {
	DynaPolyActor dyna;
	BarrelActionFunc actionFunc;
	u8 type;
} Barrel;

#endif