#pragma once
#include <string>

class LevelSettings;

class Minecraft {
public:
	Minecraft(int, char**);
  
	virtual void selectLevel(Minecraft*, std::string const&, std::string const&, LevelSettings const&);
   
//	ServerCommandParser* getCommandParser();
};