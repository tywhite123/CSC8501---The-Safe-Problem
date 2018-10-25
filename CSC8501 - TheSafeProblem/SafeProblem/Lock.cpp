
#include "Lock.h"


//Lock::Lock()
//{
//}


Lock::Lock()
{
	dials = Vec<Dial, 4>();
	CN = Vec<Dial, 4>();
	LN = Vec<Dial, 4>();
	HN = Vec<Dial, 4>();
}

Lock::Lock(int a, int b, int c, int d)
{
	//dials[0] = Dial(a);
	//dials[1] = Dial(b);
	//dials[2] = Dial(c);
	//dials[3] = Dial(d);

	dials = Vec<Dial, 4>();

	dials.insert(Dial(a));
	dials.insert(Dial(b));
	dials.insert(Dial(c));
	dials.insert(Dial(d));

	CN = Vec<Dial, 4>();
	LN = Vec<Dial, 4>();
	HN = Vec<Dial, 4>();

}

Lock::Lock(Vec<Dial, 4> Root)
{
	for(int i = 0; i < 4; ++i)
		dials.insert(Dial(Root.getAt(i).getEntry()));
}

Lock::~Lock()
{
}

void Lock::setLock(int a, int b, int c, int d)
{
	dials.insert(Dial(a));
	dials.insert(Dial(b));
	dials.insert(Dial(c));
	dials.insert(Dial(d));
}


