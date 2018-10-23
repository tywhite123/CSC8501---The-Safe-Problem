#include "FileIO.h"
#include "ConsoleIO.h"
#include "ProblemSolver.h"
#include<stdlib.h>
#include <time.h>




void generateHashes(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]);


int main() {
	
	
	
	srand(time(NULL));
	
	
	
	FileIO io;
	ConsoleIO consoleIO;
	ProblemSolver solve;

	

	std::vector<Safe*> safes;

	int mode = consoleIO.selectMode();
	
	if (1 == mode || 3 == mode) {
		int noOfS = consoleIO.inputNoOfSolutions();
		int rootGen = consoleIO.selectRandom();
		string keyFilePath = consoleIO.inputFilePath();
		string multiSafePath;
		if (3 == mode)
			multiSafePath = consoleIO.inputFilePath();

		system("CLS");

		int UHF[4];
		int LHF[4];
		int PHF[4];

		generateHashes(UHF, LHF, PHF);

		HashFunctions h(UHF, LHF, PHF);
		
		std::cout << "\n----------------------------------------------------------------------------\n\n";
		
		solve.generateRoots(safes, h, rootGen, noOfS);
		
		io.printKeyFile(keyFilePath, h, safes);

		if (mode == 3) {
			io.printMultiSafeFile(multiSafePath, safes);
			consoleIO.outputMultiSafeSolutions(safes);
		}
		else {
			consoleIO.outputHashFunctions(h, safes.size());
		}
	}
	else if (2 == mode) {
		string keyFilePath = consoleIO.inputFilePath();
		string multiSafePath = consoleIO.inputFilePath();

		HashFunctions* h;

		io.readInKeyFile(keyFilePath, h, safes);

		solve.solveRoots(safes, h);

		io.printMultiSafeFile(multiSafePath, safes);
		consoleIO.outputMultiSafeSolutions(safes);

	}
	else if (4 == mode) {
		int noOfS = consoleIO.inputNoOfSolutions();
		int rootGen = consoleIO.selectRandom();
		string lockFilePath = consoleIO.inputFilePath();


		int UHF[4];
		int LHF[4];
		int PHF[4];

		generateHashes(UHF, LHF, PHF);

		HashFunctions h(UHF, LHF, PHF);

		std::cout << "\n----------------------------------------------------------------------------\n\n";

		solve.generateRoots(safes, h, rootGen, noOfS);

		io.printLockFile(lockFilePath, safes);
		io.printKeyFile("keytesting.txt", h, safes);


	}
	else if (5 == mode) {
		string lockFilePath = consoleIO.inputFilePath();
		
		io.readInLockFile(lockFilePath, safes);
		
		for (int i = 0; i < safes.size(); ++i) {
			cout << "ROOT: " << safes[i]->getLockAt(0)->getLock()->getAt(0).getEntry()
				<< safes[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
				<< safes[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
				<< safes[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

			for (int j = 0; j < 5; ++j)
			{
				cout << "LN" << j << ": ";
				for (int k = 0; k < 4; ++k)
					cout << safes[i]->getLockAt(j)->getLN()->getAt(k).getEntry() << " ";
				cout << endl;
			}

			cout << endl;

		
		}
		
		
		
	}

	//Generating the keys

	//for generating roots for that hash
	
	//CONSOLE PRINTING
	

	for(unsigned int i = 0; i < safes.size(); ++i)
	{
		delete safes[i];
		safes[i] = NULL;
	}
	
	int exit;
	cin >> exit;
	
	return 0;
}




void generateHashes(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]) {

	UHF[0] = rand() % 19 - 9;
	UHF[1] = rand() % 19 - 9;
	UHF[2] = rand() % 19 - 9;
	UHF[3] = rand() % 19 - 9;


	LHF[0] = rand() % 19 - 9;
	LHF[1] = rand() % 19 - 9;
	LHF[2] = rand() % 19 - 9;
	LHF[3] = rand() % 19 - 9;


	PHF[0] = rand() % 19 - 9;
	PHF[1] = rand() % 19 - 9;
	PHF[2] = rand() % 19 - 9;
	PHF[3] = rand() % 19 - 9;


}





//Old algorithm
//for (int i = 0; i < noOfS; ++i) {
	//	bool isValid = true;

	//	int a, b, c, d;

	//	/*a = rand() % 10;
	//	b = rand() % 10;
	//	c = rand() % 10;
	//	d = rand() % 10;*/

	//	d = i % 10;
	//	c = i % 100 / 10;
	//	b = i % 1000 / 100;
	//	a = i / 1000;


	//	Safe* s = new Safe(a, b, c, d);

	//	//MULTI LOCK SAFE

	//	for (int j = 0; j < 5 && isValid; ++j) {
	//		Vec<Dial, 4>* Root = s->getCurrentLock()->getLock();
	//		Vec<Dial, 4>* CNHash = s->getCurrentLock()->getCN();
	//		Vec<Dial, 4>* LNHash = s->getCurrentLock()->getLN();
	//		Vec<Dial, 4>* HNHash = s->getCurrentLock()->getHN();

	//		isValid = h.hashRoot(Root, CNHash, LNHash, HNHash);

	//		

	//		if (j < 4) {
	//			s->nextLockRoot();
	//		}
	//					

	//	}

	//	if (isValid) {
	//		validSafe.push_back(s);	

	//	}
	//} 