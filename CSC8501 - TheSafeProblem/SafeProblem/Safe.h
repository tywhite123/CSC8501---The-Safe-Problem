#include "Lock.h"
#pragma once
class Safe
{
public:
	Safe(int a, int b, int c, int d);
	~Safe();

	void nextLockRoot();
	Lock getLockAt(int i) { return locks.getAt(i); }


	//void hashFunc(Lock l)

private:
	Vec<Lock, 5> locks;
	int currentLock = 0;
};

