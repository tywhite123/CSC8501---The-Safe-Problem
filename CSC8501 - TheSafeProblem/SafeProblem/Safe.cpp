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
