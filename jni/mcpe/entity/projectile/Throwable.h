#pragma once

class Throwable : public Entity
{
public:
        int shakeTime;
        bool inGround;
        int ownerId;
        int life;
        int flightTime;
        int xTile;
        int yTile;
        int zTile;
        int lastTime;
};