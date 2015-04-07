#pragma once
#include <string>

class TextureUVCoordinateSet;
class Player;
class Entity;
class Mob;
class Tile;
class Level;
class TextureAtlasTextureItem;
class ItemInstance;
class Random;

class Item {
public:
	int _maxStackSize;
	std::string _textureAtlasFile;
	int _frameCount;
	bool _animatesInToolbar;
	const int id;
	int maxDamage;
	int creativeCategory;
	bool _handEquipped;
	bool _isStackedByData;
	Item* craftingRemainingItem;
	std::string descriptionId;

	char filler_item[76];

// static fields
	static Item* items[512];
	Item(int);
	virtual ~Item();
	virtual int getMaxStackSize(const ItemInstance *);
	virtual void setMaxStackSize(int);
	virtual bool canBeDepleted();
	virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
	virtual float getIconYOffset() const;
	virtual void setIcon(const std::string &, int);
	virtual void setIcon(TextureUVCoordinateSet);
	virtual bool isMirroredArt() const;
	virtual ItemInstance &use(ItemInstance &, Player &);
	virtual bool useOn(ItemInstance *, Player *, int, int, int, signed char, float, float, float);
	virtual int getMaxUseDuration() const;
	virtual void useTimeDepleted(ItemInstance *, Level *, Player *);
	virtual int getUseAnimation() const;
	virtual void releaseUsing(ItemInstance *, Player *, int);
	virtual float getDestroySpeed(ItemInstance *, Tile *);
	virtual bool canDestroySpecial(const Tile *) const;
	virtual int getLevelDataForAuxValue(int) const;
	virtual bool isStackedByData() const;
	virtual int getMaxDamage();
	virtual int getAttackDamage(Entity *);
	virtual void hurtEnemy(ItemInstance *, Mob *, Mob *);
	virtual void interactEnemy(ItemInstance *, Mob *, Player *);
	virtual bool mineBlock(ItemInstance *, int, int, int, int, Mob *);
	virtual void handEquipped();
	virtual bool isHandEquipped() const;
	virtual bool isFood() const;
	virtual bool isSeed() const;
	virtual bool isArmor() const;
	virtual bool isLiquidClipItem(int) const;
	virtual std::string getName(const ItemInstance *) const;
	virtual std::string getDescription() const;
	virtual std::string getDescription(const ItemInstance *) const;
	virtual std::string getDescriptionId() const;
	virtual std::string getDescriptionId(const ItemInstance *) const;
	virtual void setDescriptionId(const std::string &);
	virtual bool isEmissive(int) const;
	virtual void *getAnimationFrameFor(Mob &) const; 
	static void initItems();
	static TextureAtlasTextureItem getTextureItem(const std::string &);
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string &, int);
	static ItemInstance getIDByName(const std::string &, bool);
	void setCategory(int);
	void setStackedByData(bool);
	void setMaxDamage(int);
};
