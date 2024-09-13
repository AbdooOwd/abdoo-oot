/*
 * File: z_low_table.c
 * Overlay: ovl_low_Table
 * Description: A static low wooden table. (no behaviour)
 */

#include "z_low_table.h"
#include "abdoo/utils.h"
#include "assets/objects/object_low_table/gLowTableDL.h"
#include "assets/objects/object_low_table/gLowTableDL_collision.h"

void LowTable_Init(Actor* thisx, PlayState* play);
void LowTable_Destroy(Actor* thisx, PlayState* play);
void LowTable_Update(Actor* thisx, PlayState* play);
void LowTable_Draw(Actor* thisx, PlayState* play);

const ActorInit Low_Table_InitVars = {
	ACTOR_LOW_TABLE,
	ACTORCAT_BG,
	0,	// no flags
	OBJECT_LOW_TABLE,
	sizeof(LowTable),
	LowTable_Init,
	LowTable_Destroy,
	LowTable_Update,
	LowTable_Draw
};

void LowTable_Init(Actor* thisx, PlayState* play) {
	LowTable* this = (LowTable*) thisx;

	// Initialize collision
	COLLISION_INIT(&gLowTableDL_collisionHeader)
}

void LowTable_Destroy(Actor* thisx, PlayState* play) {
	LowTable* this = (LowTable*) thisx;
	COLLISION_UNINIT()
}

void LowTable_Update(Actor* thisx, PlayState* play) {
	LowTable* this = (LowTable*) thisx;

}

void LowTable_Draw(Actor* thisx, PlayState* play) {
	LowTable* this = (LowTable*) thisx;

	Gfx_DrawDListOpa(play, gLowTableDL);
}