#include "Dial.h"



Dial::Dial()
{
}


Dial::Dial(int start) : entry(start)
{
	//TODO: Checks on the entry

}

Dial::~Dial()
{
}

Dial Dial::operator+(const int & rhs)
{
	
	for (int i = 1; i <= rhs; ++i) {
		if (entry >= 9)
			entry = 0;
		else
			entry++;

		//std::cout << entry << std::endl;
	}

	return Dial(entry);
}

Dial Dial::operator-(const int & rhs)
{
	
	for (int i = 1; i <= rhs; ++i) {
		if (entry <= 0)
			entry = 9;
		else
			entry--;

		//std::cout << entry << std::endl;
	}

	return Dial(entry);
}

int Dial::operator=(Dial & rhs)
{
	entry = rhs.getEntry();

	return 0;
}

