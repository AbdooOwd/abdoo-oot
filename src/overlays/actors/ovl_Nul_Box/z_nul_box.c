/*
 * File: z_Nul_Box.c
 * Overlay: ovl_Nul_Box
 * Description: static no-collision useless wooden box
 */

#include "z_nul_box.h"
#include "assets/objects/object_nul_box/gNulBoxDL.h"

void Nul_Box_Init(Actor* thisx, PlayState* play);
void Nul_Box_Destroy(Actor* thisx, PlayState* play);
void Nul_Box_Update(Actor* thisx, PlayState* play);
void Nul_Box_Draw(Actor* thisx, PlayState* play);

const ActorInit Nul_Box_InitVars = {
	ACTOR_NUL_BOX,
	ACTORCAT_BG,
	0,	// no flags
	OBJECT_NUL_BOX,
	sizeof(Nul_Box),
	Nul_Box_Init,
	Nul_Box_Destroy,
	Nul_Box_Update,
	Nul_Box_Draw
};

void Nul_Box_Init(Actor* thisx, PlayState* play) {
	Nul_Box* this = (Nul_Box*) thisx;

	Debug_Print(1, "I eat soup");
}

void Nul_Box_Destroy(Actor* thisx, PlayState* play) {
	Nul_Box* this = (Nul_Box*) thisx;
	
}

void Nul_Box_Update(Actor* thisx, PlayState* play) {
	Nul_Box* this = (Nul_Box*) thisx;

}

void Nul_Box_Draw(Actor* thisx, PlayState* play) {
	Nul_Box* this = (Nul_Box*) thisx;

	Gfx_DrawDListOpa(play, gNulBoxDL);
}