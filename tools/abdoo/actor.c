/*
 * File: z_ACTORFILLER.c
 * Overlay: ovl_ACTORFILLER
 * Description: filler filler
 */

#include "z_ACTORLOWER.h"

void ACTORFILLER_Init(Actor* thisx, PlayState* play);
void ACTORFILLER_Destroy(Actor* thisx, PlayState* play);
void ACTORFILLER_Update(Actor* thisx, PlayState* play);
void ACTORFILLER_Draw(Actor* thisx, PlayState* play);

const ActorProfile ACTORFILLER_Profile = {
	ACTOR_ACTORUPPER,
	ACTORCAT_BG,
	0,	// no flags
	OBJECT_GAMEPLAY_KEEP,
	sizeof(ACTORFILLER),
	ACTORFILLER_Init,
	ACTORFILLER_Destroy,
	ACTORFILLER_Update,
	ACTORFILLER_Draw
};

void ACTORFILLER_Init(Actor* thisx, PlayState* play) {
	ACTORFILLER* this = (ACTORFILLER*) thisx;

}

void ACTORFILLER_Destroy(Actor* thisx, PlayState* play) {
	ACTORFILLER* this = (ACTORFILLER*) thisx;
	
}

void ACTORFILLER_Update(Actor* thisx, PlayState* play) {
	ACTORFILLER* this = (ACTORFILLER*) thisx;

}

void ACTORFILLER_Draw(Actor* thisx, PlayState* play) {
	ACTORFILLER* this = (ACTORFILLER*) thisx;

}