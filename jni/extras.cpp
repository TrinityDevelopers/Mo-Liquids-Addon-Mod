#include "extras.h"

ItemInstance* create_ItemInstance(int id, int count, int damage)
{
	ItemInstance* instance = new ItemInstance();
	instance->count = count;
	instance->damage = damage;
	instance->_setItem(id);
	return instance;
}

Inventory* getInventory(Player* player)
{
	void* invPtr = *((void**) (((intptr_t) player) + PLAYER_INVENTORY_OFFSET));
	return (Inventory*) invPtr;
}

Level* getLevel(Player* player)
{
	void* levelPtr = *((void**) (((intptr_t) player) + PLAYER_LEVEL_OFFSET));
	return (Level*) levelPtr;
}

TileSource* getTileSource(Level* level)
{
	void* tileSource = *((void**) (((intptr_t) level) + LEVEL_TILE_SOURCE_OFFSET));
	return (TileSource*) tileSource;
}

void dropItem(Level* level, ItemInstance* instance, float x, float y, float z)
{
	TileSource* tileSource = getTileSource(level);
	ItemEntity* retval = new ItemEntity(tileSource, x, y, z, &instance const);
	level->addEntity(retval);
}

