#include "Lock.h"
#pragma once
class Safe
{
public:
	Safe();
	~Safe();

	//void hashFunc(Lock l)

private:
	Vec<Lock, 5> locks;

};

