/*
 * File: z_the_dev.c
 * Overlay: ovl_the_dev
 * Description: Trololo Floating plate
 */

#include "z_the_dev.h"
#include "assets/objects/object_trololo/gTrololoDL.h"

#define FLAGS 			(ACTOR_FLAG_0 | ACTOR_FLAG_3)
#define FOCUS_FIXER 	10

void TheDev_Init(Actor* thisx, PlayState* play);
void TheDev_Destroy(Actor* thisx, PlayState* play);
void TheDev_Update(Actor* thisx, PlayState* play);
void TheDev_Draw(Actor* thisx, PlayState* play);

u16 TheDev_getNextTextId(PlayState* play, Actor* thisx);
s16 TheDev_updateTalkState(PlayState* play, Actor* thisx);

const ActorInit the_dev_InitVars = {
	ACTOR_THE_DEV,
	ACTORCAT_NPC,
	FLAGS,
	OBJECT_TROLOLO,
	sizeof(the_dev),
	TheDev_Init,
	TheDev_Destroy,
	TheDev_Update,
	TheDev_Draw
};

typedef enum {
	DEV_MESSAGE_ID_0 = 0x0302,
} DevMessages;

void TheDev_Init(Actor* thisx, PlayState* play) {
	the_dev* this = (the_dev*) thisx;

	this->amplitude = 25;
	this->speed = 0.05;
	this->time = 0;
}

void TheDev_Destroy(Actor* thisx, PlayState* play) {
	the_dev* this = (the_dev*) thisx;
	
}

void TheDev_Update(Actor* thisx, PlayState* play) {
	the_dev* this = (the_dev*) thisx;

	// Debug_Print(1, "Home POS: %f", this->actor.home.pos.y);
	// Debug_Print(2, "Cur POS: %f", this->actor.world.pos.y);
	// Debug_Print(3, "Cur CamFuncID: 0x%x", Camera_getFuncIdx(GET_ACTIVE_CAM(play)));

	// float
	this->actor.world.pos.y = this->actor.home.pos.y +  this->amplitude * sinf(this->time);
	this->actor.focus.pos.y = this->actor.world.pos.y + FOCUS_FIXER;
	this->time += this->speed;

	Npc_UpdateTalking(
		play,
		&this->actor,
		&this->interact_info.talkState,
		50.0f,
		TheDev_getNextTextId,
		TheDev_updateTalkState
	);
}

void TheDev_Draw(Actor* thisx, PlayState* play) {
	the_dev* this = (the_dev*) thisx;

	Gfx_DrawDListOpa(play, gTrololoDL);
}

u16 TheDev_getNextTextId(PlayState* play, Actor* thisx) {
	return DEV_MESSAGE_ID_0;
}

s16 TheDev_updateTalkState(PlayState* play, Actor* thisx) {
    u16 talkState = NPC_TALK_STATE_TALKING;
    Player* player = GET_PLAYER(play);
    Camera* camera = GET_ACTIVE_CAM(play);

	switch (Message_GetState(&play->msgCtx)) {
            case TEXT_STATE_DONE:
                thisx->textId = DEV_MESSAGE_ID_0;       // reset cuz cam mode gets coco crazy
                talkState = NPC_TALK_STATE_IDLE;
                break;
            default:
				thisx->textId = play->msgCtx.textId;
                break;
    }

    return talkState;
}