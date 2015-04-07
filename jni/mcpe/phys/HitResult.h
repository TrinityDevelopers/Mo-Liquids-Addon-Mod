#pragma once

enum HitResultType
{
	TILE,
	ENITY,
	NO_HIT
};

class HitResult
{
public:
	HitResultType type;
	int f;
	TilePos tile;
	Vec3 pos;
	Entity* entity;
	bool indirectHit;
};
