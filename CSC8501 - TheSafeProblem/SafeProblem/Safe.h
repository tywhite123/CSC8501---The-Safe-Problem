#include "Lock.h"
#pragma once
class Safe
{
public:
	Safe(int a, int b, int c, int d);
	~Safe();

	void nextLockRoot();
	void nextLock();
	Lock* getLockAt(int i) { return locks.getAt(i); }
	void insertCN(Vec<Dial, 4>*& hash) { locks.getAt(currentLock)->insertCN(hash); }
	Lock* getCurrentLock() { return locks.getAt(currentLock); }
	int whichLock() { return currentLock; }

	//void hash(HashFunctions& hash);


	//void hashFunc(Lock l)

private:
	Vec<Lock*, 5> locks;
	int currentLock = 0;
};

