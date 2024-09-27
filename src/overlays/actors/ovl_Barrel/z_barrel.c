/*
 * File: z_Barrel.c
 * Overlay: ovl_Barrel
 * Description: Wooden Barrel can be used as moving-hiding spot
 * Notes: 
 * 	- If params == 0x00C0 then barrel can be used as hiding spot
 * 	- Still can't be thrown in water (game crashes when entering water while lifting barrel)
 */

#include "z_barrel.h"
#include "assets/objects/object_barrel/gBarrelDL.h"
#include "assets/objects/object_barrel/barrelCol_collision.h"

#define FLAGS			(ACTOR_FLAG_4 | ACTOR_FLAG_29)
#define BARREL_HEIGHT	60

void Barrel_Init(Actor* thisx, PlayState* play);
void Barrel_Destroy(Actor* thisx, PlayState* play);
void Barrel_Update(Actor* thisx, PlayState* play);
void Barrel_Draw(Actor* thisx, PlayState* play);

void Barrel_SetupIdle(Barrel* this, PlayState* play);
void Barrel_Idle(Barrel* this, PlayState* play);
void Barrel_SetupLiftedUp(Barrel* this, PlayState* play);
void Barrel_LiftedUp(Barrel* this, PlayState* play);

s32 Barrel_SnapToFloor(Barrel* this, PlayState* play);
void Barrel_ApplyGravity(Barrel* this);

const ActorInit Barrel_InitVars = {
	ACTOR_BARREL,
	ACTORCAT_PROP,
	FLAGS,
	OBJECT_BARREL,
	sizeof(Barrel),
	Barrel_Init,
	Barrel_Destroy,
	Barrel_Update,
	Barrel_Draw
};

void Barrel_Init(Actor* thisx, PlayState* play) {
	Barrel* this = (Barrel*) thisx;
	CollisionHeader* colHeader;

	DynaPolyActor_Init(&this->dyna, 0);
	CollisionHeader_GetVirtual(&barrelCol_collisionHeader, &colHeader);
	this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, thisx, colHeader);

	this->type = this->dyna.actor.params & 0xFF;
	
	if (!Barrel_SnapToFloor(this, play)) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

	Barrel_SetupIdle(this, play);
}

void Barrel_Destroy(Actor* thisx, PlayState* play) {
	Barrel* this = (Barrel*) thisx;

	DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
}

void Barrel_Update(Actor* thisx, PlayState* play) {
	Barrel* this = (Barrel*) thisx;
	// Player* player = GET_PLAYER(play);
	// Vec3f* playerVel = &player->actor.velocity;

	// Debug_Print(0, "Player Speed: %.3f", player->speedXZ);
	// Debug_Print(1, "PActor Speed: %.3f", player->actor.speed);
	// Debug_Print(2, "Velocity: (%.2f, %.2f, %.2f)", playerVel->x, playerVel->y, playerVel->z);

	this->actionFunc(this, play);
}

void Barrel_Draw(Actor* thisx, PlayState* play) {
	Barrel* this = (Barrel*) thisx;

	Gfx_DrawDListOpa(play, gBarrelDL);
}

void Barrel_SetupIdle(Barrel* this, PlayState* play) {
	this->actionFunc = Barrel_Idle;
	DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
}

void Barrel_Idle(Barrel* this, PlayState* play) {
	if (Actor_HasParent(&this->dyna.actor, play)) {
		// Debug_Print(3, "IM ADOPTED"); // lol
		Barrel_SetupLiftedUp(this, play);
	} else {
		if (this->dyna.actor.xzDistToPlayer < 100.0f && this->type == 0xC0) {
			Actor_OfferCarry(&this->dyna.actor, play);
		}
	}
}

void Barrel_SetupLiftedUp(Barrel* this, PlayState* play) {
    this->actionFunc = Barrel_LiftedUp;
    this->dyna.actor.room = -1;
    //! @bug: This is an unsafe cast, although the sound effect will still play
    Player_PlaySfx((Player*)&this->dyna.actor, NA_SE_PL_PULL_UP_POT);
    this->dyna.actor.flags |= ACTOR_FLAG_4;
	DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
}

void Barrel_LiftedUp(Barrel* this, PlayState* play) {
    if (Actor_HasNoParent(&this->dyna.actor, play)) {
        this->dyna.actor.room = play->roomCtx.curRoom.num;
        Barrel_SetupIdle(this, play);
        Barrel_ApplyGravity(this);
        Actor_UpdatePos(&this->dyna.actor);
        Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 5.0f, 15.0f, 0.0f,
                                UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_7);
		Barrel_SnapToFloor(this, play);
	}
}


/* useful */
s32 Barrel_SnapToFloor(Barrel* this, PlayState* play) {
    CollisionPoly* groundPoly;
    Vec3f pos;
    s32 bgId;
    f32 groundY;

    pos.x = this->dyna.actor.world.pos.x;
    pos.y = this->dyna.actor.world.pos.y + 20.0f;
    pos.z = this->dyna.actor.world.pos.z;
    groundY = BgCheck_EntityRaycastDown4(&play->colCtx, &groundPoly, &bgId, &this->dyna.actor, &pos);
    if (groundY > BGCHECK_Y_MIN) {
        this->dyna.actor.world.pos.y = groundY;
        Math_Vec3f_Copy(&this->dyna.actor.home.pos, &this->dyna.actor.world.pos);
		return true;
    } else {
        return false;
    }
}

void Barrel_ApplyGravity(Barrel* this) {
    this->dyna.actor.velocity.y += this->dyna.actor.gravity;
    if (this->dyna.actor.velocity.y < this->dyna.actor.minVelocityY) {
        this->dyna.actor.velocity.y = this->dyna.actor.minVelocityY;
    }
}