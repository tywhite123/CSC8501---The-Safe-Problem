#include "FileIO.h"
#include <time.h>


void generateHashes(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]);


int main() {


	srand(time(NULL));

	int UHF[4];
	int LHF[4];
	int PHF[4];

	generateHashes(UHF, LHF, PHF);

	HashFunctions h(UHF, LHF, PHF);
	

	std::vector<Lock> validRoots;
	std::vector<Safe*> validSafe;

	int noOfS;
	std::cin >> noOfS;
	
	std::cout << "\n----------------------------------------------------------------------------\n\n";

	for (int i = 0; i < noOfS; ++i) {
		bool isValid = true;

		int a, b, c, d;

		/*a = rand() % 10;
		b = rand() % 10;
		c = rand() % 10;
		d = rand() % 10;*/

		d = i % 10;
		c = i % 100 / 10;
		b = i % 1000 / 100;
		a = i / 1000;




		Safe* s = new Safe(a, b, c, d);

		//MULTI LOCK SAFE

		for (int j = 0; j < 5 && isValid; ++j) {
			//Lock* l = s->getCurrentLock();
			Vec<Dial, 4>* Root = s->getCurrentLock()->getLock();
			Vec<Dial, 4>* CNHash = s->getCurrentLock()->getCN();
			Vec<Dial, 4>* LNHash = s->getCurrentLock()->getLN();
			Vec<Dial, 4>* HNHash = s->getCurrentLock()->getHN();

			isValid = h.hashRoot(Root, CNHash, LNHash, HNHash);

			

			if (j < 4) {
				s->nextLockRoot();
			}


			

		}

		if (isValid) {
			validSafe.push_back(s);	

		}
	}  

















		//TODO: THINGS THAT NEED TO BE MOVED




		//CONSOLE PRINTING

	for (int i = 0; i < validSafe.size(); ++i){
		std::cout << "\tSolution " << i+1 << std::endl << std::endl;

		std::cout << "\tROOT:\t" << validSafe[i]->getLockAt(0)->getLock()->getAt(0).getEntry()
		<< validSafe[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
		<< validSafe[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
		<< validSafe[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

				for (int j = 0; j < 5; ++j) {
					std::cout << "\tCN" << j << ":";
					for (int k = 0; k < 4; k++)
						std::cout << validSafe[i]->getLockAt(j)->getCN()->getAt(k).getEntry();
					std::cout << "\t"; //<< std::endl;

					std::cout << "LN" << j << ":";
					for (int k = 0; k < 4; k++)
 						std::cout << validSafe[i]->getLockAt(j)->getLN()->getAt(k).getEntry();
					std::cout << "\t"; //<< std::endl;

					std::cout << "HN" << j << ":";
					for (int k = 0; k < 4; k++)
						std::cout << validSafe[i]->getLockAt(j)->getHN()->getAt(k).getEntry();
					std::cout << std::endl;
				}

				
				
				/*
				cout << "ROOT:\t";
				for(int i = 0; i < 4; ++i)
					cout << NS1.root[i];
				cout << endl;
				
				
				*/


				std::cout << "\n----------------------------------------------------------------------------\n\n";
			
			}

		

	std::cout << "Total Number of Solutions: " << validSafe.size();
	




	//FILE IO	
	//TODO: Move into a seperate file

	FileIO io;

	io.printKeyFile("key_file(test).txt", h, validSafe);

	io.printMultiSafeFile("multi_safe(test).txt", validSafe);


	for(int i = 0; i < validSafe.size(); ++i)
	{
		delete validSafe[i];
		validSafe[i] = NULL;
	}
	
	return 0;
}




void generateHashes(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]) {

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

}