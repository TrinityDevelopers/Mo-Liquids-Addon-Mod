#pragma once

enum class Type : int 
{
	Normal,
	Gas,
	Liquid,
	Decoration,
	Portal
};

class Material
{
public:
	static Material water;
	static Material air;
	static Material leaves;
	static Material vegetable;
	static Material dirt;
	static Material lava;
	static Material replaceable_plant;
	static Material wood;
	static Material stone;
	static Material sand;
	static Material plant;
	static Material cake;
	static Material decoration;
	static Material topSnow;
	static Material cloth;
	static Material glass;
	static Material web;
	static Material metal;
	static Material ice;
	static Material snow;
	static Material clay;
	static Material fire;
	static Material sponge;
	static Material explosive;
	static Material coral;
	static Material cactus;
	static Material portal;
	static Material bed;

	bool flammable;
	bool neverBuildable;
	bool alwaysDestroyable;
	bool replaceable;
	bool liquid;
	float translucency;
	bool blocksMotion;
	bool solid;
};