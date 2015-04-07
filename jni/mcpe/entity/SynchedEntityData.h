#pragma once

class DataItem
{
public:
	const int type;
	const int id;
	bool dirty;
};


class SynchedEntityData
{
public:
	std::map<int, DataItem*> itemsById;
	bool _isDirty;

};
