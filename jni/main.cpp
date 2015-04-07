#include <string.h>
#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <stdint.h>
#include <map>
#include <Substrate.h>
#include <extras.h>
#include "mcpe/tile/MilkTile.h"
#include "mcpe/level/TileSource.h"
#include "mcpe/item/ItemInstance.h"
#include "mcpe/tile/Tile.h"
#include "mcpe/Minecraft.h"
#include "mcpe/inventory/Inventory.h"
#include "mcpe/GameMode.h"
#include "mcpe/item/Item.h"

bool tileAdded = false;
bool reg = false;
Level* theLevel;
Inventory* theInventory;
GameMode* theGamemode;
TileSource* theTileSource;
const int MILK_TILE_ID = 25;

GameMode::InitPlayerReal GameMode::initPlayer_real = NULL;
MilkTile* MilkTile::milk = NULL;

std::map <std::string, std::string>* I18n$strings;
static void (*Tile$initTiles_real)();
static void (*Minecraft$selectLevel_real)(Minecraft*, std::string const&, std::string const&, LevelSettings const&);
static void (*Minecraft$tick_real)(Minecraft*, int, int);
static void (*CreativeInventoryScreen$populateTile_real)(void*, Tile*, int, int);
static void (*Item$initItems_real)();
static void (*ItemInstance$useOn_real)(ItemInstance*, Player*, int, int, int, signed char, float, float, float);

static void Minecraft$selectLevel_hook(Minecraft* minecraft, std::string const& string1, std::string const& string2, LevelSettings const& settings) {
    if(!reg) {
		reg = true;
		(*I18n$strings)["tile.Milk.name"]="Milk";
	}
    Minecraft$selectLevel_real(minecraft, string1, string2, settings);
}

static void Minecraft$tick_hook(Minecraft* minecraft, int i1, int i2) {
	Minecraft$tick_real(minecraft, i1, i2);
}

void GameMode::initPlayer_hook(GameMode* gm, Player* player) {
	theGamemode = gm;
	GameMode::initPlayer_real(gm, player);
}

static void Tile$initTiles_hook() {
	Tile$initTiles_real();
	MilkTile::milk = new MilkTile(MILK_TILE_ID);
}

static void Item$initItems_hook() {
	Item$initItems_real();
}

static void CreativeInventoryScreen$populateTile_hook(void* creativeInv, Tile* tile, int count, int damage){
	if(tileAdded = false) {
		CreativeInventoryScreen$populateTile_real(creativeInv, Tile::tiles[MILK_TILE_ID], 1, 0);
		tileAdded = true;
	}
	CreativeInventoryScreen$populateTile_real(creativeInv, tile, count, damage);
}

static void ItemInstance$useOn_hook(ItemInstance* itemStack, Player* player, int x, int y, int z, signed char ch1, float f1, float f2, float f3) {
	ItemInstance$useOn_real(itemStack, player, x, y, z, ch1, f1, f2, f3);
	
	theLevel = getLevel(player);
	theTileSource = getTileSource(theLevel);
	theInventory = getInventory(player);
	
	if(itemStack->item->id == 325 && itemStack->damage == 1) {
		TileID milkTileID = MilkTile::milk->id;
		theTileSource->setTile(x, y + 1, z, milkTileID, 3);
		if(theGamemode->isSurvivalType() == true) {
			--itemStack->count;
			ItemInstance* emptyBucket = create_ItemInstance(325, 1, 0);
			theInventory->add(emptyBucket);
		}
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void * handle = dlopen("libminecraftpe.so", RTLD_LAZY);

	void* Minecraft$selectLevel = dlsym(RTLD_DEFAULT, "_ZN9Minecraft11selectLevelERKSsS1_RK13LevelSettings");
	void* Minecraft$tick = dlsym(RTLD_DEFAULT, "_ZN9Minecraft4tickEii");
	void* populateTile = dlsym(RTLD_DEFAULT, "_ZN23CreativeInventoryScreen12populateItemEP4Tileii");
	void* ItemInstance$useOn = dlsym(RTLD_DEFAULT, "_ZN12ItemInstance5useOnEP6Playeriiiafff");
	
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems_hook, (void**) &Item$initItems_real);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles_hook, (void**) &Tile$initTiles_real);
	MSHookFunction(ItemInstance$useOn, (void*) &ItemInstance$useOn_hook, (void**) &ItemInstance$useOn_real);
	MSHookFunction(Minecraft$selectLevel, (void*) &Minecraft$selectLevel_hook, (void**) &Minecraft$selectLevel_real);
	MSHookFunction(populateTile, (void*) &CreativeInventoryScreen$populateTile_hook, (void**) &CreativeInventoryScreen$populateTile_real);
	MSHookFunction(Minecraft$tick, (void*) &Minecraft$tick_hook, (void**) &Minecraft$tick_real);
	MSHookFunction((void*) &GameMode::initPlayer, (void*) &GameMode::initPlayer_hook, (void**) &GameMode::initPlayer_real);
	
	I18n$strings = (std::map <std::string, std::string>*) dlsym(RTLD_DEFAULT, "_ZN4I18n8_stringsE");
    
	return JNI_VERSION_1_2;
}
