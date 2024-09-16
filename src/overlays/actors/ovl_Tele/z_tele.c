/*
 * File: z_Tele.c
 * Overlay: ovl_Tele
 * Description: A Television
 */

#include "z_tele.h"
#include "assets/objects/object_tele/gTeleDL.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void Tele_Init(Actor* thisx, PlayState* play);
void Tele_Destroy(Actor* thisx, PlayState* play);
void Tele_Update(Actor* thisx, PlayState* play);
void Tele_Draw(Actor* thisx, PlayState* play);

u16 Tele_getNextTextId(PlayState* play, Actor* thisx);
s16 Tele_updateTalkState(PlayState* play, Actor* thisx);

const ActorInit Tele_InitVars = {
	ACTOR_TELE,
	ACTORCAT_BG,
	FLAGS,
	OBJECT_TELE,
	sizeof(Tele),
	Tele_Init,
	Tele_Destroy,
	Tele_Update,
	Tele_Draw
};

f32 scale_factor = 0;

enum {
	TELE_INFO_TEXT_ID = 0x304,
};

void Tele_Init(Actor* thisx, PlayState* play) {
	Tele* this = (Tele*) thisx;

	Math_Vec3f_Copy(&this->home_scale, &this->actor.scale);
	this->bounce_speed = 0.1;
	this->scale_amplitude = 0.15;
	this->time = 0;
}

void Tele_Destroy(Actor* thisx, PlayState* play) {
	Tele* this = (Tele*) thisx;
	
}

void Tele_Update(Actor* thisx, PlayState* play) {
	Tele* this = (Tele*) thisx;

	// bouncing
	scale_factor = 1 + this->scale_amplitude * sinf(this->time);
	this->actor.scale.z = this->home_scale.z * scale_factor;
	this->actor.scale.y = this->home_scale.y / scale_factor;
	this->time += this->bounce_speed;

	Npc_UpdateTalking(
		play,
		&this->actor,
		&this->interact_info.talkState,
		50.0f,
		Tele_getNextTextId,
		Tele_updateTalkState
	);
}

void Tele_Draw(Actor* thisx, PlayState* play) {
	Tele* this = (Tele*) thisx;

	Gfx_DrawDListOpa(play, gTeleDL);
}

u16 Tele_getNextTextId(PlayState* play, Actor* thisx) {
	return TELE_INFO_TEXT_ID;
}

s16 Tele_updateTalkState(PlayState* play, Actor* thisx) {
    u16 talkState = NPC_TALK_STATE_TALKING;
    Player* player = GET_PLAYER(play);
    Camera* camera = GET_ACTIVE_CAM(play);

	switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_DONE:
            thisx->textId = TELE_INFO_TEXT_ID;
            talkState = NPC_TALK_STATE_IDLE;
            break;
        default:
			thisx->textId = play->msgCtx.textId;
            break;
    }

    return talkState;
}