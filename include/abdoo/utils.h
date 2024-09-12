#ifndef ABDOO_UTILS_H
#define ABDOO_UTILS_H

#define COLLISION_INIT(object_colHeader_addr) \
	CollisionHeader* colHeader = NULL; \
	CollisionHeader_GetVirtual(object_colHeader_addr, &colHeader); \
	this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);

#define COLLISION_UNINIT() DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
#endif