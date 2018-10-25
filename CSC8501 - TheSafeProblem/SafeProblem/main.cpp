#include "FileIO.h"
#include "ConsoleIO.h"
#include "ProblemSolver.h"
#include<stdlib.h>
#include <time.h>


int main() {
	
	
	srand((unsigned int)time(NULL));
	
	
	
	FileIO io;
	ConsoleIO consoleIO;
	ProblemSolver solve;

	
	HashFunctions* h = nullptr;
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

		
		std::cout << "\n----------------------------------------------------------------------------\n\n";
		
		solve.generateRoots(safes, h, rootGen, noOfS);

		noOfS = consoleIO.confirmAmount(safes);

		if (noOfS < (int)safes.size()) {
			for (int i = noOfS; i < (int)safes.size(); ++i) {
				delete safes[i];
			}
			safes.resize(noOfS);
		}
		
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

		try {
			io.readInKeyFile(keyFilePath, h, safes);
			
			solve.solveRoots(safes, h);

			io.printMultiSafeFile(multiSafePath, safes);
			consoleIO.outputMultiSafeSolutions(safes);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}

		

	}
	else if (4 == mode) {
		int noOfS = consoleIO.inputNoOfSolutions();
		int rootGen = consoleIO.selectRandom();
		string lockFilePath = consoleIO.inputFilePath();

		std::cout << "\n----------------------------------------------------------------------------\n\n";

		solve.generateRoots(safes, h, rootGen, noOfS);

		noOfS = consoleIO.confirmAmount(safes);

		if (noOfS < (int)safes.size()) {
			for (int i = noOfS; i < (int)safes.size(); ++i) {
				delete safes[i];
			}
			safes.resize(noOfS);
		}

		consoleIO.outputMultiSafeSolutions(safes);

		io.printLockFile(lockFilePath, safes);
		io.printKeyFile("keytesting.txt", h, safes);


	}
	else if (5 == mode) {
		string lockFilePath = consoleIO.inputFilePath();
		int locksPerSafe = consoleIO.inputNoOfLocks();


		io.readInLockFile(lockFilePath, safes, locksPerSafe);

		bool valid = solve.solveLocks(safes, h);


		if (valid) {
			consoleIO.outputLockSolution(h, safes);

			io.printKeyFile("key(fromLock).txt", h, safes);
			io.printMultiSafeFile("multi(fromLock).txt", safes);
		}
		else {
			consoleIO.nothingFound();
		}
		
	}

	if(h != nullptr)
		delete h;
	for(unsigned int i = 0; i < safes.size(); ++i)
	{
		delete safes[i];
		safes[i] = NULL;
	}
	
	consoleIO.endOfProgram();
	
	return 0;
}




//void generateHashes(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]) {
//
//	UHF[0] = rand() % 19 - 9;
//	UHF[1] = rand() % 19 - 9;
//	UHF[2] = rand() % 19 - 9;
//	UHF[3] = rand() % 19 - 9;
//
//
//	LHF[0] = rand() % 19 - 9;
//	LHF[1] = rand() % 19 - 9;
//	LHF[2] = rand() % 19 - 9;
//	LHF[3] = rand() % 19 - 9;
//
//
//	PHF[0] = rand() % 19 - 9;
//	PHF[1] = rand() % 19 - 9;
//	PHF[2] = rand() % 19 - 9;
//	PHF[3] = rand() % 19 - 9;
//
//
//}





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