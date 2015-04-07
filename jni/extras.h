#ifndef EXTRAS_H_
#define EXTRAS_H_

#include "mcpe/inventory/Inventory.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/entity/item/ItemEntity.h"
#include "mcpe/level/Level.h"

#include <sstream>
#include <stdlib.h>
#include <stdint.h>
#include <android/log.h>
#include <dlfcn.h>
#include <map>

#define PLAYER_INVENTORY_OFFSET 3212
#define PLAYER_LEVEL_OFFSET 68
#define LEVEL_TILE_SOURCE_OFFSET 2976


class TileSource;
class Level;
class Player;
class ItemInstance;

ItemInstance* getSlot(Player* player, int slot);
Inventory* getInventory(Player* player);
Level* getLevel(Player* player);
TileSource* getTileSource(Level* level);
void dropItem(Level*, ItemInstance*, float, float, float);

#endif
