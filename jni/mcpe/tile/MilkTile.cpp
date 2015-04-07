#include "MilkTile.h"
#include "Tile.h"
#include "../Material.h"
#include "TileTypeEnum.h"
#include "RenderLayerEnum.h"
#include "../item/TileItem.h"

MilkTile::MilkTile(int id) : Tile(id, "flowing_water", &Material::water) {
	this->setDescriptionId("Milk");
	this->setCategory(1);
	this->renderLayer = RENDERLAYER_BLEND;
	this->tileType = LiquidTile;
	Tile::tiles[id] = this;
	Tile::translucency[id] = Tile::translucency[10];
	Tile::solid[id] = false;
	TileItem* tileItem = new TileItem(id - 256);
}

bool MilkTile::isLiquidTile(){
	return true;
}

int MilkTile::getColor(int idc) {
	return 0xFFFFFF;
}

int MilkTile::getColor(TileSource* ts, int i1, int i2, int i3) {
	return 0xFFFFFF;
}

AABB* MilkTile::getAABB(TileSource* tilesource, int u, int v, int w, AABB& aabb, int x, bool y, int z) {
	return Tile::calmLava->getAABB(tilesource, u, v, w, aabb, x, y, z);
}


