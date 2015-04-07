#pragma once

#include "../Entity.h"
#include "../../item/ItemInstance.h"
#include "../../level/TileSource.h"

class CompoundTag;

class ItemEntity : public Entity
{
public:
	ItemInstance item;
	int age;
	int throwTime;
	float bobOffs;
private:
	int tickCount;
	int health;
	int lifeTime;
public:
	ItemEntity(TileSource &);
	ItemEntity(TileSource &, float, float, float, ItemInstance const&);
	virtual void addAdditionalSaveData(CompoundTag*);
	virtual void burn(int);
	virtual void checkInTile(float, float, float);
	virtual int getEntityTypeId(void);
	virtual void getHandleWaterAABB();
	virtual void getLifeTime();
	virtual void hurt(Entity*, int);
	virtual bool isItemEntity();
	virtual bool isPushable();
	virtual void normalTick();
	virtual void playerTouch();
	virtual void readAdditionalSaveData(CompoundTag*);
};
