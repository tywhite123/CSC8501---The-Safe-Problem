
#include "Lock.h"


//Lock::Lock()
//{
//}


Lock::Lock()
{
}

Lock::Lock(int a, int b, int c, int d)
{
	//dials[0] = Dial(a);
	//dials[1] = Dial(b);
	//dials[2] = Dial(c);
	//dials[3] = Dial(d);

	dials.insert(Dial(a));
	dials.insert(Dial(b));
	dials.insert(Dial(c));
	dials.insert(Dial(d));

}

Lock::~Lock()
{
}
