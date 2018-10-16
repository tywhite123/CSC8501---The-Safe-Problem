#include "Dial.h"
#pragma once


class Lock
{
public:
	Lock();
	Lock(int a, int b, int c, int d);
	~Lock();


	Dial getAt(int i) { return dials[i]; }



	


private:
	Dial dials[4];
	

};

