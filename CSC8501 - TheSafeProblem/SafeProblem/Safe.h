#include "Lock.h"
#pragma once
class Safe
{
public:
	Safe(int a, int b, int c, int d);
	Safe(int a, int b, int c, int d, int size);
	~Safe();

	void nextLockRoot();
	void nextLock();
	Lock* getLockAt(int i) { return locks.getAt(i); }
	void setLock(int i, int a, int b, int c, int d) { locks.getAt(i)->setLock(a, b, c, d); }
	void insertCN(Vec<Dial, 4>*& hash) { locks.getAt(currentLock)->insertCN(hash); }
	Lock* getCurrentLock() { return locks.getAt(currentLock); }
	int whichLock() { return currentLock; }
	int size() { return locks.size(); }
	void resize(int size) { locks.resize(size); }

	//void hash(HashFunctions& hash);


	//void hashFunc(Lock l)

private:
	

	Vec<Lock*, 5> locks;
	int currentLock = 0;
};

