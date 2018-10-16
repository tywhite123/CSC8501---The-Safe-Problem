#include "Lock.h"
#include"Vec.cpp"


//Lock::Lock()
//{
//}


Lock::Lock()
{
}

Lock::Lock(int a, int b, int c, int d)
{
	dials[0] = Dial(a);
	dials[1] = Dial(b);
	dials[2] = Dial(c);
	dials[3] = Dial(d);
}

Lock::~Lock()
{
}




int main() {
	//Dial d[] = { Dial(3),Dial(4),Dial(5),Dial(8) };

	////d1 + 50;
	//for (int i = 0; i < 4; i++)
	//	std::cout << d[i].getEntry();
	//std::cout << std::endl;

	//d[0] - 24;
	//d[1] + 2;
	//d[2] + 56;
	//d[3] - 19;

	//for (int i = 0; i < 4; i++)
	//	std::cout << d[i].getEntry();
	//std::cout << std::endl;

	//d[0] - 3;
	//d[1] + 2;
	//d[2] - 5;
	//d[3] + 19;

	//for (int i = 0; i < 4; i++)
	//	std::cout << d[i].getEntry();
	//std::cout << std::endl;


	int a, b, c, d;
	std::cout << "Please Enter Root: " << std::endl;
	std::cin >> a >> b >> c >> d;

	int uhfA, uhfB, uhfC, uhfD;
	int lhfA, lhfB, lhfC, lhfD;
	int phfA, phfB, phfC, phfD;

	std::cout << "Please Enter Hashing: " << std::endl;
	std::cin >> uhfA >> uhfB >> uhfC >> uhfD;
	/*std::cout << "Please Enter Root: " << std::endl;
	std::cin >> lhfA >> lhfB >> lhfC >> lhfD;
	std::cout << "Please Enter Root: " << std::endl;
	std::cin >> phfA >> phfB >> phfC >> phfD;*/

	Lock l(a,b,c,d);

	Dial CN[4];
	/*Dial LN[4];
	Dial HN[4];*/

	CN[0] = l.getAt(0) + uhfA;
	CN[1] = l.getAt(1) + uhfB; 
	CN[2] = l.getAt(2) + uhfC; 
	CN[3] = l.getAt(3) + uhfD;
	
	
	for (int i = 0; i < 4; i++)
		std::cout << CN[i].getEntry();
	std::cout << std::endl;
	

	Vec<Dial, 4> lock1(Dial(3), Dial(4), Dial(9), Dial(7));
	//Vec<Lock, 5> safe;

	lock1.getAt(0) + 10;

	return 0;
}