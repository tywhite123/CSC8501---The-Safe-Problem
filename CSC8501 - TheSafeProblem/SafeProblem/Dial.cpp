#include "Dial.h"



Dial::Dial()
{
}


Dial::Dial(int start) : entry(start)
{
	if (start < 0) {
		start = 10 - start;
	}

	//TODO: Checks on the entry

}

Dial::~Dial()
{
}

Dial Dial::operator+(const int & rhs)
{
	int j = entry;
	if (rhs < 0) {
		//use the - operator if the value is negative
		return Dial(operator-(-rhs));

	}
	else {
		for (int i = 1; i <= rhs; ++i) {
			//loop back to 0 if the value is 9 so that it gives dial like functionality
			if (j >= 9)
				j = 0;
			else
				j++;

		}
	}

	return Dial(j);
}

Dial Dial::operator-(const int & rhs)
{
	int j = entry;
	for (int i = 1; i <= rhs; ++i) {
		if (j <= 0)
			j = 9;
		else
			j--;

		//std::cout << entry << std::endl;
	}

	return Dial(j);
}

int Dial::operator=(Dial & rhs)
{
	entry = rhs.getEntry();

	return 0;
}

