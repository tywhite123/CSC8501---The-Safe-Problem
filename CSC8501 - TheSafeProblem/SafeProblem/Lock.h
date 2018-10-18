#include "Dial.h"
#include "Vec.cpp"
#pragma once


class Lock
{
public:
	Lock();
	Lock(int a, int b, int c, int d);
	~Lock();


	Dial getAt(int i) { return dials.getAt(i); }
	Vec<Dial, 4> getLock() { return dials; }



	


private:
	//Dial dials[4];
	Vec<Dial, 4> dials;
	
	

};

