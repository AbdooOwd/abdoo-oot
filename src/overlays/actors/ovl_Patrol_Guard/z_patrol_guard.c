/*
 * File: z_Patrol_Guard.c
 * Overlay: ovl_Patrol_Guard
 * Description: Patrols and looks for player. Triggers alarm if sees player for +2sec.
 */

#include "z_patrol_guard.h"
#include "assets/objects/object_joe/gJoeDL.h"

#define FLAGS		(ACTOR_FLAG_0 | ACTOR_FLAG_3)
#define JOES_HEIGHT	60	// probably?

void PatrolGuard_Init(Actor* thisx, PlayState* play);
void PatrolGuard_Destroy(Actor* thisx, PlayState* play);
void PatrolGuard_Update(Actor* thisx, PlayState* play);
void PatrolGuard_Draw(Actor* thisx, PlayState* play);

const ActorInit Patrol_Guard_InitVars = {
	ACTOR_PATROL_GUARD,
	ACTORCAT_ENEMY,
	FLAGS,	// no flags
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
}

void PatrolGuard_Destroy(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;
	
}

void PatrolGuard_Update(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;

}

void PatrolGuard_Draw(Actor* thisx, PlayState* play) {
	PatrolGuard* this = (PatrolGuard*) thisx;

	Gfx_DrawDListOpa(play, gJoeDL);
}