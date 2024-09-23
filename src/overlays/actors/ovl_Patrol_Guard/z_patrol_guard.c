/*
 * File: z_Patrol_Guard.c
 * Overlay: ovl_Patrol_Guard
 * Description: Patrols and looks for player. Triggers alarm (param 0x000A) if sees player for +2sec.
 */

#include "z_patrol_guard.h"
#include "assets/objects/object_joe/gJoeDL.h"

#define FLAGS		(ACTOR_FLAG_0 | ACTOR_FLAG_3)
#define JOES_HEIGHT	64.0f	// probably? 6.4m * 10
#define GUARD_SPEED	2.4f

void PatrolGuard_Init(Actor* thisx, PlayState* play);
void PatrolGuard_Destroy(Actor* thisx, PlayState* play);
void PatrolGuard_Update(Actor* thisx, PlayState* play);
void PatrolGuard_Draw(Actor* thisx, PlayState* play);

void PatrolGuard_SetupWait(PatrolGuard* this);
void PatrolGuard_SetupPatrol(PatrolGuard* this);

void PatrolGuard_Wait(PatrolGuard* this, PlayState* play);
void PatrolGuard_Patrol(PatrolGuard* this, PlayState* play);

void PatrolGuard_checkPlayer(PatrolGuard* this, PlayState* play);

// TODO: Take EN_HEISHI1 as example

extern f32 Camera_LERPCeilF(f32 target, f32 cur, f32 stepScale, f32 minDiff);

const ActorInit Patrol_Guard_InitVars = {
	ACTOR_PATROL_GUARD,
	ACTORCAT_ENEMY,
	FLAGS,
	OBJECT_JOE,
	sizeof(PatrolGuard),
	PatrolGuard_Init,
	PatrolGuard_Destroy,
	PatrolGuard_Update,
	PatrolGuard_Draw
};

void PatrolGuard_Init(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;

	this->actor.focus.pos.y += JOES_HEIGHT;

	this->headPos.y = this->actor.focus.pos.y;
	this->path = this->actor.params & 0xFF;
	this->moveSpeed = GUARD_SPEED;
	this->waypoint = 0;
	this->goForward = true;

	PatrolGuard_SetupWait(this);
}

void PatrolGuard_Destroy(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;
	
}

void PatrolGuard_Update(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;

	this->actor.focus.pos.x = this->actor.world.pos.x;
	this->actor.focus.pos.z = this->actor.world.pos.z;

	this->spottedPlayer = Actor_IsFacingPlayer(&this->actor, DEG_TO_BINANG(45)) && this->actor.xzDistToPlayer < 500.0f;
	PatrolGuard_checkPlayer(this, play);
	this->actionFunc(this, play);
}

void PatrolGuard_Draw(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;

	Gfx_DrawDListOpa(play, gJoeDL);
}

void PatrolGuard_SetupWait(PatrolGuard* this) {
	this->patrolTimer = 0;
	this->actionFunc = PatrolGuard_Wait;
}

void PatrolGuard_Wait(PatrolGuard* this, PlayState* play) {
	Debug_Print(0, "timer: %d", this->patrolTimer);

	// if 0xFF00 of actor params (time to wait) reached
	if (this->patrolTimer >= ((this->actor.params >> 8) & 0xFF) * 10) {
		this->patrolTimer = 0;
		PatrolGuard_SetupPatrol(this);
	}
	
	this->patrolTimer++;
}

void PatrolGuard_SetupPatrol(PatrolGuard* this) {
	if (this->goForward)
		this->waypoint++;
	else
		this->waypoint--;
	
	this->actionFunc = PatrolGuard_Patrol;
}

void PatrolGuard_Patrol(PatrolGuard* this, PlayState* play) {
	Path* path = &play->pathList[this->path];
	Vec3s* pointPos = SEGMENTED_TO_VIRTUAL(path->points);
	Vec3f* actorPos = &this->actor.world.pos;
	f32 pathDiffX;
	f32 pathDiffZ;

	if (this->waypoint == path->count) {
		this->goForward = false;
		this->waypoint -= 2;
	} else if (this->waypoint == 0) {
		this->goForward = true;
	}

	pointPos += this->waypoint;

	pathDiffX = pointPos->x - actorPos->x;
	pathDiffZ = pointPos->z - actorPos->z;

	Debug_Print(1, "Going to waypoint: %d", this->waypoint);
	Debug_Print(2, "diff: X%.3f, Z%.3f", pathDiffX, pathDiffZ);

	if (ABS(pathDiffX) <= 1.0f && ABS(pathDiffZ) <= 1.0f) {
		Debug_Print(3, "Time to wait");
		PatrolGuard_SetupWait(this);
	}
	
	Math_ApproachF(&actorPos->x, pointPos->x, 0.4f, this->moveSpeed);
	Math_ApproachF(&actorPos->z, pointPos->z, 0.4f, this->moveSpeed);
}

void PatrolGuard_checkPlayer(PatrolGuard* this, PlayState* play) {
	Camera* camera = GET_ACTIVE_CAM(play);
	Player* player = GET_PLAYER(play);

	// if guard is facing player
	// and not too far away from it then guard can see player

	if (this->spottedPlayer) {
		// TODO: Add "FOV Infiltration ON/OFF" in (future) settings for player to choose
		
		// fov effect
		if (player->hidden) {
			this->targetFov = 100.0f;
			camera->eyeNext.y = player->actor.world.pos.y + 200;
		} else {
			this->targetFov = 125.0f;
			camera->eyeNext.y = player->actor.world.pos.y + 50;
		}

		if (this->actor.xzDistToPlayer < 150.0f)	// only set camera's at when too close
			camera->at = this->actor.world.pos;

		camera->fov = Camera_LERPCeilF(this->targetFov, camera->fov, camera->fovUpdateRate * 2, 1.0f);
		camera->dist = OLib_Vec3fDist(&camera->at, &player->actor.world.pos);
	}
}