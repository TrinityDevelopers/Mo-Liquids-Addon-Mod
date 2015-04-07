#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <memory>

#include "util/SmallSet.h"
#include "entity/Entity.h"
#include "world/level/LightUpdate.h"
#include "world/level/TilePos.h"

typedef unsigned char TileID;
typedef unsigned char DataID;
typedef unsigned char Brightness;
typedef long unsigned int RandomSeed;

typedef std::unordered_map<int, Entity*> EntityMap;
typedef std::unordered_set<Player*> PlayerList;
typedef std::vector<LevelListener*> ListenerList;
typedef std::unordered_set<TileSource*> RegionSet;
typedef std::vector<Token> List;
typedef std::vector<LightUpdate> LightUpdateList;
typedef std::vector<PRInfo> PendingList;
typedef std::priority_queue<TickNextTickData> TickDatSet;
typedef std::vector<Entity*> EntityList;
typedef std::vector<TilePos> LightList;
typedef std::unordered_set<TileSourceListener *> ListenerSet;
typedef SmallSet<std::unique_ptr<Entity>> OwnedEntitySet;

typedef struct FullTile
{
	TileID id;
	DataID data;
};


/*
 * TODO:
 *
 * 	MojangConnector
 * 	Screen
 * 	LevelChunk
 * 	...
 *
 * */

class LevelListener; //Interface
class LevelStorage; // Abstract?

class IRakNetInstance; // Interface Class
class LevelStorageSource; //Interface?
class NetEventCallback; //Interface?
class MojangConnector; // Do you really need this class?
class _TickPtr; // WTH???????
class Screen;
class LevelChunk; //Do you really need this?
// {
// public:
// 	Level& level;
// 	const TilePos min;
// 	const TilePos max;
// 	const ChunkPos pos;
// 	const bool readOnly;
// 	ChunkSource* generator;
// 	LevelChunkFormat loadedFormat;
// 	LightList blockLightSources;
// 	std::string serializedEntitiesBuffer;
// 	std::atomic<ChunkState> loadState;
// 	Tick lastTick;
// 	//Incomplete!
// };

