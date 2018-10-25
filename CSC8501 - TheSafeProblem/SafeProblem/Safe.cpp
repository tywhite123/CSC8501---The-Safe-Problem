#include "Safe.h"



Safe::Safe(int a, int b, int c, int d)
{
	locks = Vec<Lock*, 5>();
	locks.insert(new Lock(a, b, c, d));
	
}

Safe::Safe(int a, int b, int c, int d, int size)
{
	locks = Vec<Lock*, 5>();
	locks.resize(size);
	locks.insert(new Lock(a, b, c, d));
}


Safe::~Safe()
{
	for (int i = 0; i < locks.size(); ++i)
		delete locks.getAt(i);
}

void Safe::nextLockRoot()
{
	++currentLock;
	locks.insert(new Lock(*locks.getAt(currentLock-1)->getHN()));

}

void Safe::nextLock()
{
	++currentLock;
	locks.insert(new Lock());
}

//void Safe::hash(HashFunctions & hash)
//{
//	for (int i = 0; i < 4; ++i)
//		getCurrentLock()->getCN()->insert(getCurrentLock()->getLock().getAt(i) + hash.getUHF().getAt(i));
//}
