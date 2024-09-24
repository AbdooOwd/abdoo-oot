/*
 * File: z_patrol_guard.c
 * Overlay: ovl_Patrol_Guard
 * Description: Patrols and follows path. (unfinished actor and description [WIP])
 * Notes:
 * 	- How actor params work: 0xFEAA: 
 * 		- AA: Path ID
 * 		- E: Time to wait at path point once there
 * 		- F: Type 	- 0: Loop Path (from end to point 0 directly) + Camera Effects
 * 					- 1: Loop Path + No Camera Effects
 * 					- 2: Limit Path (goes back when reach end) + Camera Effects
 * 					- 3: Limit Path + No Camera Effects
 *  - "EN_Heishi1" has been taken as example for this actor.
 *  - I could've just Copy-Pasted the Gerudo's or Hyrule Castle's Guards code,
 *    but that's a way to learn!
 *  - When the type is an odd number, it means Camera Effects are ON.
 */

#include "z_patrol_guard.h"
#include "assets/objects/object_joe/gJoeDL.h"

#define FLAGS					(ACTOR_FLAG_0 | ACTOR_FLAG_2| ACTOR_FLAG_4)	// idk what these flags are for
#define JOES_HEIGHT				64.0f	// probably? 6.4m * 10
#define GUARD_SPEED				2.0f
#define GUARD_BGM_FADE_DURATION	0x17
#define GUARD_SMOOTH_STEP		3400

void PatrolGuard_Init(Actor* thisx, PlayState* play);
void PatrolGuard_Destroy(Actor* thisx, PlayState* play);
void PatrolGuard_Update(Actor* thisx, PlayState* play);
void PatrolGuard_Draw(Actor* thisx, PlayState* play);

void PatrolGuard_SetupWait(PatrolGuard* this);
void PatrolGuard_SetupPatrol(PatrolGuard* this);

void PatrolGuard_Wait(PatrolGuard* this, PlayState* play);
void PatrolGuard_Patrol(PatrolGuard* this, PlayState* play);

void PatrolGuard_checkPlayer(PatrolGuard* this, PlayState* play);
void PatrolGuard_cameraEffects(PatrolGuard* this, PlayState* play);

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

bool bgmLowered = false;

void PatrolGuard_Init(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;

	// TODO: If I make Guards be able to climb small heights,
	// -> this focus-Y-pos setting will be useless
	this->actor.focus.pos.y += JOES_HEIGHT;

	this->guardData.pathId = this->actor.params & 0xFF;			 // 0x00FF
	this->guardData.type = (this->actor.params >> 8) & 0xF0;	 // 0xF000
	this->guardData.waitTime = (this->actor.params >> 8) & 0x0F; // 0x0F00

	// TODO: seems like setting `this->path` to `this->guardData.pathId` gives an incorrect value
	// resulting in wrong path for guard (going through walls and off-path)
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

	/* Do this if guards become able to climb small heights
	this->actor.focus.pos.y = this->actor.world.pos.y + JOES_HEIGHT;
	*/
	this->actor.focus.pos.x = this->actor.world.pos.x;
	this->actor.focus.pos.z = this->actor.world.pos.z;

	/**
	 * Might be better to do `this->actor.focus.pos = this->actor.world.pos`
	 * then increment Focus Y pos by joe's height.
	*/

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
	// Debug_Print(0, "Timer: %.2f", this->patrolTimer / 10.0f);

	// if 0xFF00 of actor params (time to wait) reached
	if (this->patrolTimer >= this->guardData.waitTime * 10) {
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
	Vec3s* pointPos = SEGMENTED_TO_VIRTUAL(path->points);	// TODO: should try understaning that...
	Vec3f* actorPos = &this->actor.world.pos;
	Player* player = GET_PLAYER(play);	// TODO: find another way to access `->hidden`
	f32 pathDiffX;
	f32 pathDiffZ;

	// TODO: optimize function
	// TODO: optimize + clean + tidy if statement

	// checks if we're at the end/start of the path (holy shii that's some messy code)
	if (this->waypoint == path->count) {
		// if is of type "Loop Path"
		if (this->guardData.type == 0 || this->guardData.type == 1) {
			this->waypoint = 0;
		} else {
			this->goForward = false;
			this->waypoint -= 2;
		}
	} else if (this->waypoint == 0) {
		this->goForward = true;
	}

	pointPos += this->waypoint;
	pathDiffX = pointPos->x - actorPos->x;
	pathDiffZ = pointPos->z - actorPos->z;

	// Debug_Print(1, "Path: %d / Waypoint: %d", this->path, this->waypoint);

	if (!this->spottedPlayer || player->hidden) {
		Math_SmoothStepToS(&this->actor.shape.rot.y, 
							RAD_TO_BINANG(Math_FAtan2F(pathDiffX, pathDiffZ)), 3, GUARD_SMOOTH_STEP, 0);
		Math_SmoothStepToF(&actorPos->x, pointPos->x, 3.0f, this->moveSpeed, 0.0f);
		Math_SmoothStepToF(&actorPos->z, pointPos->z, 3.0f, this->moveSpeed, 0.0f);
	} else {
		Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 3, GUARD_SMOOTH_STEP, 0);
		this->patrolTimer = 0;
	}

	if (((fabsf(pathDiffX) < 20.0f) && fabsf(pathDiffZ) < 20.0f) || (this->patrolTimer <= 0 && !this->spottedPlayer)) {
		PatrolGuard_SetupWait(this);
	}
}

// Does actions based on if and how guard sees player
void PatrolGuard_checkPlayer(PatrolGuard* this, PlayState* play) {
	// TODO: Tidy if statements to separately manage cam effects and game logic

	// TODO: now that i think of it, playing music is kinda useless. more useless code, that's it.
	// -> but f* this, it's fun (but i love optimization).

	// TODO: don't play music if already playing.
	// -> if 2 guards spot player at the same time, music will play twice (?)

	if (this->spottedPlayer && !bgmLowered) {
		Audio_SetMainBgmVolume(0x10, GUARD_BGM_FADE_DURATION);
		SEQCMD_PLAY_SEQUENCE(SEQ_PLAYER_BGM_SUB, GUARD_BGM_FADE_DURATION, 0, NA_BGM_ENEMY);
		bgmLowered = true;
	} else if (!this->spottedPlayer && bgmLowered) {
		SEQCMD_PLAY_SEQUENCE(SEQ_PLAYER_BGM_SUB, GUARD_BGM_FADE_DURATION, 0, NA_BGM_NO_MUSIC);
		Audio_SetMainBgmVolume(0x7F, GUARD_BGM_FADE_DURATION);
		bgmLowered = false;
	}

	// TODO: is doing `x == 0 || x == 2` faster than `x % 2 == 0`?

	// if type allows camera effects
	if (this->guardData.type == 0 || this->guardData.type == 2)
		PatrolGuard_cameraEffects(this, play);
}

void PatrolGuard_cameraEffects(PatrolGuard* this, PlayState* play) {
	Camera* camera = GET_ACTIVE_CAM(play);
	Player* player = GET_PLAYER(play);
	f32 targetFov;

	// TODO: TOO MUCH IF STATEMENTS! AND THEY'RE TOO COMPLICATED!
	// -> I'M SURE IT CAN BE OPTIMIZED AND TIDIED!
	// -> THERE ARE IF STATEMENTS IN IF STATEMENTS.
	// -> AND MOST OF THEM HAVE THE SAME CONDITIONS, JUST
	// -> IN A DIFFERENT ORDER!!1!!1!

	// TODO: Fix camera going coco crazy:
	//	-	Camera dist when close and hidden (barrel)
	//	-	Camera too close to barrel (can't see shii)

	// Debug_Print(3, "camDist: %.2f | eyeY: %.2f", camera->dist, camera->eye.y);

	
	if (this->actor.xzDistToPlayer < 150.0f || this->spottedPlayer) {
		camera->at = this->actor.world.pos;
	}

	// if guard is facing player and not too far away 
	// from it then guard can see player
	if (this->spottedPlayer) {
		// TODO: Add "FOV Infiltration ON/OFF" in (future) settings for player to choose
		// TODO: Optimize. Runs every frame (efficient, but can be enhanced)

		// fov effect
		if (player->hidden) {
			targetFov = 75.0f;
			if (this->actor.xzDistToPlayer < 150.0f) {
				camera->dist = OLib_Vec3fDist(&camera->at, &player->actor.world.pos) * 1.5f;
			} else {
				camera->dist = OLib_Vec3fDist(&camera->at, &player->actor.world.pos) * 1.2f;
			}
			/*camera->eyeNext.y = player->actor.world.pos.y + 200;
			camera->eyeNext.x = player->actor.world.pos.x;
			camera->eyeNext.z = player->actor.world.pos.z;*/
		} else {
			targetFov = 86.0f;
			camera->dist = OLib_Vec3fDist(&camera->at, &player->actor.world.pos);
		}

		camera->fov = Camera_LERPCeilF(targetFov, camera->fov, camera->fovUpdateRate * 2, 1.0f);
	}
}