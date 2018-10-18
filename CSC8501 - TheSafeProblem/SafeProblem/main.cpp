#include "Lock.h"
#include "HashFunctions.h"
#include <time.h>

int main() {


	srand(time(NULL));

	HashFunctions h;

	int print = 0;

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

	std::cout << "\n----------------------------------------------------------------------------\n\n";

	int noOfS;
	std::cin >> noOfS;

	for (int i = 0; i < noOfS; ++i) {

		bool isValid = true;
		/*std::cout << "Solution " << i + 1 << std::endl << std::endl;*/

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

		//std::cout << "ROOT:\t" << a << b << c << d << std::endl;


		Lock l(a, b, c, d);

		//h.hashRoot(l.getLock());

		Dial CN[5][4];
		Dial LN[5][4];
		Dial HN[5][4];

		for (int j = 0; j < 5; ++j) {

			if (j == 0) {

				CN[j][0] = l.getAt(0) + uhfA;
				CN[j][1] = l.getAt(1) + uhfB;
				CN[j][2] = l.getAt(2) + uhfC;
				CN[j][3] = l.getAt(3) + uhfD;
			}
			else
			{
				CN[j][0] = HN[j-1][0] + lhfA;
				CN[j][1] = HN[j-1][1] + lhfB;
				CN[j][2] = HN[j-1][2] + lhfC;
				CN[j][3] = HN[j-1][3] + lhfD;
			}

			//std::cout << "CN" << j << ":";
			//for (int i = 0; i < 4; i++)
			//	std::cout << CN[j][i].getEntry();
			//std::cout << "\t"; //<< std::endl;


			LN[j][0] = CN[j][0] + lhfA;
			LN[j][1] = CN[j][1] + lhfB;
			LN[j][2] = CN[j][2] + lhfC;
			LN[j][3] = CN[j][3] + lhfD;
						 
			//std::cout << "LN" << j << ":";
			//for (int i = 0; i < 4; i++)
			//	std::cout << LN[j][i].getEntry();
			//std::cout << "\t"; //<< std::endl;



			HN[j][0] = LN[j][0] + phfA;
			HN[j][1] = LN[j][1] + phfB;
			HN[j][2] = LN[j][2] + phfC;
			HN[j][3] = LN[j][3] + phfD;

			/*std::cout << "HN" << j << ":";
			for (int i = 0; i < 4; i++)
				std::cout << HN[j][i].getEntry();
			std::cout << std::endl;*/

			
			//How the check with work
			for (int i = 0; i < 3 /*|| isValid*/; ++i) {
				for (int k = i + 1; k < 4 /*|| isValid*/; ++k) {
					//std::cout << "Comparing: " << CN[i].getEntry() << " & " << CN[j].getEntry() << std::endl;
					if (CN[j][i].getEntry() == CN[j][k].getEntry()) {
						//std::cout << "They are the same value, so invalid CN" << std::endl;
						isValid = false;
						break;
					}
				}
			}

		}

		if (isValid) {

			++print;
			std::cout << "\tSolution " << print << std::endl << std::endl;

			std::cout << "\tROOT:\t" << a << b << c << d << std::endl;

			for (int j = 0; j < 5; ++j) {
				std::cout << "\tCN" << j << ":";
				for (int i = 0; i < 4; i++)
					std::cout << CN[j][i].getEntry();
				std::cout << "\t"; //<< std::endl;

				std::cout << "LN" << j << ":";
				for (int i = 0; i < 4; i++)
					std::cout << LN[j][i].getEntry();
				std::cout << "\t"; //<< std::endl;

				std::cout << "HN" << j << ":";
				for (int i = 0; i < 4; i++)
					std::cout << HN[j][i].getEntry();
				std::cout << std::endl;
			}

			

			std::cout << "\n----------------------------------------------------------------------------\n\n";

		}

		/*std::cout << "\n----------------------------------------------------------------------------\n\n";*/
	}

	std::cout << "Total Number of Solutions: " << print;
	
	return 0;
}