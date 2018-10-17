#include <iostream>
#pragma once
class Dial
{
public:
	Dial();
	Dial(int start);
	~Dial();

	Dial operator+(const int& rhs);
	Dial operator-(const int& rhs);
	int operator=(Dial& rhs);

	int getEntry() { return entry; }


private:

	int entry;

};

