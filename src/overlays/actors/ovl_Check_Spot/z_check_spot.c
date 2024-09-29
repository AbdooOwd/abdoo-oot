/*
 * File: z_check_spot.c
 * Overlay: ovl_CheckSpot
 * Description: Invisible Z-Target, displays message (based on params)
 */

#include "z_check_spot.h"

#define FLAGS	(ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4)

void CheckSpot_Init(Actor* thisx, PlayState* play);
void CheckSpot_Destroy(Actor* thisx, PlayState* play);
void CheckSpot_Update(Actor* thisx, PlayState* play);
void CheckSpot_Draw(Actor* thisx, PlayState* play);

const ActorInit Check_Spot_InitVars = {
	ACTOR_CHECK_SPOT,
	ACTORCAT_BG,
	FLAGS,
	OBJECT_GAMEPLAY_KEEP,
	sizeof(CheckSpot),
	CheckSpot_Init,
	CheckSpot_Destroy,
	CheckSpot_Update,
	CheckSpot_Draw
};

void CheckSpot_Init(Actor* thisx, PlayState* play) {
	CheckSpot* this = (CheckSpot*) thisx;

	this->actor.textId = this->actor.params + 0x0300;
	this->dist = 300.0f;
}

void CheckSpot_Destroy(Actor* thisx, PlayState* play) {
	CheckSpot* this = (CheckSpot*) thisx;
	
}

void CheckSpot_Update(Actor* thisx, PlayState* play) {
	CheckSpot* this = (CheckSpot*) thisx;

	if (sqrtf(this->actor.xyzDistToPlayerSq) <= this->dist && Player_IsFacingActor(&this->actor, DEG_TO_BINANG(45), play)) {
		Actor_OfferTalk(&this->actor, play, this->dist);
	}
}

void CheckSpot_Draw(Actor* thisx, PlayState* play) {
	CheckSpot* this = (CheckSpot*) thisx;

}