#include "Safe.h"
#include "HashFunctions.h"
#include <time.h>
#include <vector>
#include <fstream>

int main() {


	srand(time(NULL));
	//srand(700000);

	
	//bool isValid = true;
	int print = 0;


	int UHF[4];
	int LHF[4];
	int PHF[4];

	UHF[0] = rand() % 10;
	UHF[1] = rand() % 10;
	UHF[2] = rand() % 10;
	UHF[3] = rand() % 10;

	if (rand() % 2 == 0)
		UHF[0] = -UHF[0];
	if (rand() % 2 == 0)
		UHF[1] = -UHF[1];
	if (rand() % 2 == 0)
		UHF[2] = -UHF[2];
	if (rand() % 2 == 0)
		UHF[3] = -UHF[3];

	std::cout << "UHF:\t" << UHF[0] << ", " << UHF[1] << ", " << UHF[2] << ", " << UHF[3] << std::endl;


	LHF[0] = rand() % 19 - 9;
	LHF[1] = rand() % 19 - 9;
	LHF[2] = rand() % 19 - 9;
	LHF[3] = rand() % 19 - 9;

	std::cout << "LHF:\t" << LHF[0] << ", " << LHF[1] << ", " << LHF[2] << ", " << LHF[3] << std::endl;

	PHF[0] = rand() % 19 - 9;
	PHF[1] = rand() % 19 - 9;
	PHF[2] = rand() % 19 - 9;
	PHF[3] = rand() % 19 - 9;

	std::cout << "PHF:\t" << PHF[0] << ", " << PHF[1] << ", " << PHF[2] << ", " << PHF[3] << std::endl;

	HashFunctions h(UHF, LHF, PHF);

	std::vector<Lock> validRoots;

	int noOfS;
	std::cin >> noOfS;
	
	std::cout << "\n----------------------------------------------------------------------------\n\n";

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

				CN[j][0] = l.getAt(0) + UHF[0];
				CN[j][1] = l.getAt(1) + UHF[1];
				CN[j][2] = l.getAt(2) + UHF[2];
				CN[j][3] = l.getAt(3) + UHF[3];
			}
			else
			{
				CN[j][0] = HN[j-1][0] + LHF[0];
				CN[j][1] = HN[j-1][1] + LHF[1];
				CN[j][2] = HN[j-1][2] + LHF[2];
				CN[j][3] = HN[j-1][3] + LHF[3];
			}

			//std::cout << "CN" << j << ":";
			//for (int i = 0; i < 4; i++)
			//	std::cout << CN[j][i].getEntry();
			//std::cout << "\t"; //<< std::endl;


			LN[j][0] = CN[j][0] + LHF[0];
			LN[j][1] = CN[j][1] + LHF[1];
			LN[j][2] = CN[j][2] + LHF[2];
			LN[j][3] = CN[j][3] + LHF[3];
						 
			//std::cout << "LN" << j << ":";
			//for (int i = 0; i < 4; i++)
			//	std::cout << LN[j][i].getEntry();
			//std::cout << "\t"; //<< std::endl;



			HN[j][0] = LN[j][0] + PHF[0];
			HN[j][1] = LN[j][1] + PHF[1];
			HN[j][2] = LN[j][2] + PHF[2];
			HN[j][3] = LN[j][3] + PHF[3];

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
			validRoots.push_back(l);
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

	std::ofstream keyFile("key_file.txt");

	if (keyFile) {
		keyFile << "NS " << validRoots.size() << std::endl;

		for(int i = 0; i < validRoots.size(); ++i)
		{
			keyFile << "ROOT " << validRoots[i].getAt(0).getEntry()
				<< validRoots[i].getAt(1).getEntry()
				<< validRoots[i].getAt(2).getEntry()
				<< validRoots[i].getAt(3).getEntry() << std::endl;

			keyFile << "UHF " << UHF[0] << ","
				<< UHF[1] << ","
				<< UHF[2] << ","
				<< UHF[3] << std::endl;

			keyFile << "LHF " << LHF[0] << ","
				<< LHF[1] << ","
				<< LHF[2] << ","
				<< LHF[3] << std::endl;

			keyFile << "PHF " << PHF[0] << ","
				<< PHF[1] << ","
				<< PHF[2] << ","
				<< PHF[3] << std::endl;
		}
	}

	keyFile.close();
	
	return 0;
}