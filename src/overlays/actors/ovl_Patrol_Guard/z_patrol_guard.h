#ifndef Z_PATROL_GUARD_H
#define Z_PATROL_GUARD_H

#include "ultra64.h"
#include "global.h"

struct PatrolGuard;

typedef void (*PatrolGuardActionFunc)(struct PatrolGuard*, PlayState*);
typedef struct PatrolGuard {
	Actor actor;
	PatrolGuardActionFunc actionFunc;
	Vec3f headPos;
	f32 targetFov;
	u16 patrolTimer;
	f32 moveSpeed;
	s16 path;
	s16 waypoint;
	bool goForward;
	bool spottedPlayer;
} PatrolGuard;

#endif