#pragma once

class Random
{
public:
	RandomSeed _seed;
	long unsigned int[636] _mt; // 636 is that right?
	int _mti;
	bool haveNextNextGaussian;
	float nextNextGaussian;
};
