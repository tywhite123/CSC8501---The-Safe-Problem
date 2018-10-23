#include "Safe.h"



Safe::Safe(int a, int b, int c, int d)
{
	locks.insert(new Lock(a, b, c, d));
}


Safe::~Safe()
{
	for (int i = 0; i < 5; ++i)
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
