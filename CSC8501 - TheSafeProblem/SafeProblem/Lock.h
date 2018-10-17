#include "Dial.h"
#include "Vec.cpp"
#pragma once


class Lock
{
public:
	Lock();
	Lock(int a, int b, int c, int d);
	~Lock();


	Dial getAt(int i) { return lock.getAt(i); }



	


private:
	//Dial dials[4];
	Vec<Dial, 4> lock;
	
	

};

