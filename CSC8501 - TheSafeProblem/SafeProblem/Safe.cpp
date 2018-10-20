#include "Safe.h"



Safe::Safe(int a, int b, int c, int d)
{
	locks.insert(Lock(a, b, c, d));
}


Safe::~Safe()
{
}

void Safe::nextLockRoot()
{
	++currentLock;
	locks.insert(Lock(*locks.getAt(currentLock-1).getHN()));

}

//void Safe::hash(HashFunctions & hash)
//{
//	for (int i = 0; i < 4; ++i)
//		getCurrentLock()->getCN()->insert(getCurrentLock()->getLock().getAt(i) + hash.getUHF().getAt(i));
//}
