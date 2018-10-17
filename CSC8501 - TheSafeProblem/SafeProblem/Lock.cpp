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

	lock.insert(Dial(a));
	lock.insert(Dial(b));
	lock.insert(Dial(c));
	lock.insert(Dial(d));

}

Lock::~Lock()
{
}


#include <time.h>

int main() {


	srand(time(NULL));
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

	for (int i = 0; i < 10; ++i) {
		std::cout << "Solution " << i+1 << std::endl << std::endl;

		int a, b, c, d;
		/*std::cout << "Please Enter Root: " << std::endl;
		std::cin >> a >> b >> c >> d;*/

		a = rand() % 10;
		b = rand() % 10;
		c = rand() % 10;
		d = rand() % 10;

		std::cout << "ROOT:\t" << a << b << c << d << std::endl;


		int uhfA, uhfB, uhfC, uhfD;
		int lhfA, lhfB, lhfC, lhfD;
		int phfA, phfB, phfC, phfD;

		uhfA = rand() % 10;
		uhfB = rand() % 10;
		uhfC = rand() % 10;
		uhfD = rand() % 10;

		std::cout << "UHF:\t" << uhfA << uhfB << uhfC << uhfD << std::endl;

		/*std::cout << "Please Enter Hashing: " << std::endl;
		std::cin >> uhfA >> uhfB >> uhfC >> uhfD;
		std::cout << "Please Enter Root: " << std::endl;
		std::cin >> lhfA >> lhfB >> lhfC >> lhfD;
		std::cout << "Please Enter Root: " << std::endl;
		std::cin >> phfA >> phfB >> phfC >> phfD;*/

		Lock l(a, b, c, d);

		Dial CN[4];
		Dial LN[4];
		Dial HN[4];

		CN[0] = l.getAt(0) + uhfA;
		CN[1] = l.getAt(1) + uhfB;
		CN[2] = l.getAt(2) + uhfC;
		CN[3] = l.getAt(3) + uhfD;

		std::cout << "CN:\t";
		for (int i = 0; i < 4; i++)
			std::cout << CN[i].getEntry();
		std::cout << std::endl;



		//How the check with work
		for (int i = 0; i < 3; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				std::cout << "Comparing: " << CN[i].getEntry() << " & " << CN[j].getEntry() << std::endl;
				if (CN[i].getEntry() == CN[j].getEntry()) {
					std::cout << "They are the same value, so invalid CN" << std::endl;
				}
			}
		}

		std::cout << "\n----------------------------------------------------------------------------\n\n";
	}

	 //LN[0] = CN[0] + lhfA;
	 //LN[1] = CN[1] + lhfB;
	 //LN[2] = CN[2] + lhfC;
	 //LN[3] = CN[3] + lhfD;


	 //for (int i = 0; i < 4; i++)
		// std::cout << LN[i].getEntry();
	 //std::cout << std::endl;



	 //HN[0] = LN[0] + phfA;
	 //HN[1] = LN[1] + phfB;
	 //HN[2] = LN[2] + phfC;
	 //HN[3] = LN[3] + phfD;


	 //for (int i = 0; i < 4; i++)
		// std::cout << HN[i].getEntry();
	 //std::cout << std::endl;
	



	//Vec<Dial, 4> lock1;
	////Vec<Lock, 5> safe;

	//lock1.insert(Dial(3));
	//lock1.insert(Dial(3));
	//lock1.insert(Dial(3));
	//lock1.insert(Dial(3));

	//lock1.getAt(0) + 10;

	return 0;
}