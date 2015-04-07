#pragma once
#include <string.h>
#include "../Material.h"
#include "Tile.h"

class MilkTile: public Tile {
public:
	static MilkTile* milk;
public:
	MilkTile(int id);
	virtual bool isLiquidTile();
	virtual int getColor(int); // 47
	virtual int getColor(TileSource*, int, int, int); // 48
	virtual AABB* getAABB(TileSource*, int, int, int, AABB&, int, bool, int);
	virtual void use(Player*, int, int, int);
};
