#ifndef Z_PATROL_GUARD_H
#define Z_PATROL_GUARD_H

#include "ultra64.h"
#include "global.h"

struct PatrolGuard;

typedef void (*PatrolGuardActionFunc)(struct PatrolGuard*, PlayState*);
typedef struct PatrolGuard {
	Actor actor;
	PatrolGuardActionFunc actionFunc;
	u16 patrolTimer;
	f32 moveSpeed;
	s16 path;
	s16 waypoint;
	bool goForward;
	bool spottedPlayer;
	union {
		u8 waitTime;
		u8 type;
		u8 pathId;	// TODO: Seems broken. setting it is fine, using somewhere else gives incorrect value tho
	} guardData;
} PatrolGuard;

#endif