#pragma once
#include <string>
#include <vector>
#include <functional>
#include <GLES/gl.h>
#include "Item.h"

class Player;
class Mob;
class Level;
class Entity;
class Tile;
class CompoundTag;

class ItemInstance {
public:
	int count; //0
	int damage; //4
	Item* item;//8
	void* block; //12
	bool wtf; //16
	bool wtf2; //17
	bool wtf3; //18
	bool wtf4; //19
	ItemInstance();
	ItemInstance(int, int, int);
	ItemInstance(bool);
	ItemInstance(const ItemInstance &);
	ItemInstance(const Item *);
	ItemInstance(const Item *, int);
	ItemInstance(const Item *, int, int);
	virtual void _setItem(int);
	virtual void canDestroySpecial(Tile *);
	virtual ItemInstance *clone(const ItemInstance *);
	virtual ItemInstance *cloneSafe(const ItemInstance *);
	virtual void fromTag(CompoundTag *);
	virtual int getAttackDamage(Entity *);
	virtual int getAuxValue() const;
	virtual int getDamageValue() const;
	virtual int getDescriptionId() const;
	virtual int getDestroySpeed(Tile *);
	virtual void getIcon(int, bool) const;
	virtual int getId() const;
	virtual int getMaxDamage() const;
	virtual int getMaxStackSize() const;
	virtual int getMaxUseDuration() const;
	virtual std::string getName() const;
	virtual int getUseAnimation() const;
	virtual void hurtAndBreak(int, Mob *);
	virtual void hurtEnemy(Mob *, Mob *);
	virtual void init(int, int, int);
	virtual void interactEnemy(Mob *, Player *);
	virtual bool isArmorItem(const ItemInstance *);
	virtual bool isDamageableItem() const;
	virtual bool isDamaged() const;
	virtual bool isItem(const ItemInstance *);
	virtual bool isLiquidClipItem();
	virtual bool isNull() const;
	virtual bool isStackable(const ItemInstance *, const ItemInstance *);
	virtual bool isStackable() const;
	virtual bool isStackedByData() const;
	virtual void load(CompoundTag *);
	virtual bool matches(const ItemInstance *) const;
	virtual bool matches(const ItemInstance *, const ItemInstance *);
	virtual bool matchesNulls(ItemInstance const *, const ItemInstance *);
	virtual void mineBlock(int, int, int, int, Mob *);
	virtual bool operator==(const ItemInstance &) const;
	virtual void releaseUsing(Player *, int);
	virtual void remove(int);
	virtual void sameItemAndAux(ItemInstance *) const;
	virtual void save(CompoundTag *);
	virtual void setAuxValue(int);
	virtual void setDescriptionId(const std::string &);
	virtual void setNull();
	virtual void snap(Player *);
	virtual std::string toString() const;
	virtual void use(Player &);
	virtual void useAsFuel();
	virtual void useTimeDepleted(Level *, Player *);
	
	static void useOn(ItemInstance*, Player *, int, int, int, signed char, float, float, float);
};