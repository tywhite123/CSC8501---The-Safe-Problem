#include "Lock.h"
#include "HashFunctions.h"
#include <time.h>

int main() {


	srand(time(NULL));

	HashFunctions h;


	int uhfA, uhfB, uhfC, uhfD;
	int lhfA, lhfB, lhfC, lhfD;
	int phfA, phfB, phfC, phfD;

	uhfA = rand() % 10;
	uhfB = rand() % 10;
	uhfC = rand() % 10;
	uhfD = rand() % 10;

	if (rand() % 2 == 0)
		uhfA = -uhfA;
	if (rand() % 2 == 0)
		uhfB = -uhfB;
	if (rand() % 2 == 0)
		uhfC = -uhfC;
	if (rand() % 2 == 0)
		uhfD = -uhfD;

	std::cout << "UHF:\t" << uhfA << ", " << uhfB << ", " << uhfC << ", " << uhfD << std::endl;


	lhfA = rand() % 19 - 9;
	lhfB = rand() % 19 - 9;
	lhfC = rand() % 19 - 9;
	lhfD = rand() % 19 - 9;

	std::cout << "LHF:\t" << lhfA << ", " << lhfB << ", " << lhfC << ", " << lhfD << std::endl;

	phfA = rand() % 19 - 9;
	phfB = rand() % 19 - 9;
	phfC = rand() % 19 - 9;
	phfD = rand() % 19 - 9;

	std::cout << "PHF:\t" << phfA << ", " << phfB << ", " << phfC << ", " << phfD << std::endl;

	int noOfS;
	std::cin >> noOfS;

	for (int i = 0; i < noOfS; ++i) {
		std::cout << "Solution " << i + 1 << std::endl << std::endl;

		int a, b, c, d;
		/*std::cout << "Please Enter Root: " << std::endl;
		std::cin >> a >> b >> c >> d;*/

		/*a = rand() % 10;
		b = rand() % 10;
		c = rand() % 10;
		d = rand() % 10;*/

		d = i % 10;
		c = i % 100 / 10;
		b = i % 1000 / 100;
		a = i / 1000;

		std::cout << "ROOT:\t" << a << b << c << d << std::endl;


		Lock l(a, b, c, d);

		h.hashRoot(l.getLock());

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


		LN[0] = CN[0] + lhfA;
		LN[1] = CN[1] + lhfB;
		LN[2] = CN[2] + lhfC;
		LN[3] = CN[3] + lhfD;

		std::cout << "LN:\t";
		for (int i = 0; i < 4; i++)
			std::cout << LN[i].getEntry();
		std::cout << std::endl;



		HN[0] = LN[0] + phfA;
		HN[1] = LN[1] + phfB;
		HN[2] = LN[2] + phfC;
		HN[3] = LN[3] + phfD;

		std::cout << "HN:\t";
		for (int i = 0; i < 4; i++)
			std::cout << HN[i].getEntry();
		std::cout << std::endl;

		bool isValid = true;
		//How the check with work
		for (int i = 0; i < 3 /*|| isValid*/; ++i) {
			for (int j = i + 1; j < 4 /*|| isValid*/; ++j) {
				//std::cout << "Comparing: " << CN[i].getEntry() << " & " << CN[j].getEntry() << std::endl;
				if (CN[i].getEntry() == CN[j].getEntry()) {
					std::cout << "They are the same value, so invalid CN" << std::endl;
					isValid = false;
					break;
				}
			}
		}

		std::cout << "\n----------------------------------------------------------------------------\n\n";
	}


	
	return 0;
}