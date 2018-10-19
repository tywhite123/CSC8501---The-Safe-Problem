#include "Dial.h"
#include "Vec.cpp"
#pragma once


class Lock
{
public:
	Lock();
	Lock(int a, int b, int c, int d);
	Lock(Vec<Dial, 4> Root);
	~Lock();


	Dial getAt(int i) { return dials.getAt(i); }
	Vec<Dial, 4> getLock() { return dials; }

	Vec<Dial, 4>* getCN() { return &CN; }
	Vec<Dial, 4>* getLN() { return &LN; }
	Vec<Dial, 4>* getHN() { return &HN; }




	


private:
	//Dial dials[4];
	Vec<Dial, 4> dials;
	Vec<Dial, 4> CN;
	Vec<Dial, 4> LN;
	Vec<Dial, 4> HN;
	
	

};

