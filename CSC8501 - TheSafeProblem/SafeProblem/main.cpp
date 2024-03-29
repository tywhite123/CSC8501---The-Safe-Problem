#include "FileIO.h"
#include "ConsoleIO.h"
#include "ProblemSolver.h"
#include<stdlib.h>
#include <time.h>

#define KEYDIR "..\\Files\\KeyFiles\\"
#define MULTIDIR "..\\Files\\MultiSafeFiles\\"
#define LOCKDIR "..\\Files\\LockFiles\\"

#define KEY "Key"
#define MULTI "Multi Safe"
#define LOCK "LOCK"


int main() {
	
	
	srand((unsigned int)time(NULL));
	
	
	
	FileIO io;
	ConsoleIO consoleIO;
	ProblemSolver solve;

	
	HashFunctions* h = nullptr;
	std::vector<Safe*> safes;

	safes.reserve(100);

	int mode = consoleIO.selectMode();
	
	if (1 == mode || 3 == mode) {
		int noOfS = consoleIO.inputNoOfSolutions();
		int rootGen = consoleIO.selectRandom();
		int locksPerSafe = consoleIO.inputNoOfLocks();
		int bonus = consoleIO.bonusValidation();
		string keyFilePath = consoleIO.inputFilePath(KEY);
		string multiSafePath;
		if (3 == mode)
			multiSafePath = consoleIO.inputFilePath(MULTI);

		system("CLS");

		
		std::cout << "\n----------------------------------------------------------------------------\n\n";
		
		solve.generateRoots(safes, h, rootGen, noOfS, locksPerSafe, bonus);

		noOfS = consoleIO.confirmAmount(safes);

		if (noOfS < (int)safes.size()) {
			for (int i = noOfS; i < (int)safes.size(); ++i) {
				delete safes[i];
			}
			safes.resize(noOfS);
		}
		
		io.printKeyFile(KEYDIR + keyFilePath, h, safes);

		if (mode == 3) {
			io.printMultiSafeFile(MULTIDIR + multiSafePath, safes);
			consoleIO.outputMultiSafeSolutions(safes);
		}
		else {
			consoleIO.outputHashFunctions(h, safes.size());
		}
	}
	else if (2 == mode) {
		string keyFilePath = consoleIO.inputFilePath(KEY);
		string multiSafePath = consoleIO.inputFilePath(MULTI);
		int bonus = consoleIO.bonusValidation();

		try {
			io.readInKeyFile(KEYDIR + keyFilePath, h, safes);
			
			solve.solveRoots(safes, h, bonus);

			io.printMultiSafeFile(MULTIDIR + multiSafePath, safes);
			consoleIO.outputMultiSafeSolutions(safes);
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}

		

	}
	else if (4 == mode) {
		int noOfS = consoleIO.inputNoOfSolutions();
		int rootGen = consoleIO.selectRandom();
		int locksPerSafe = consoleIO.inputNoOfLocks();
		int bonus = consoleIO.bonusValidation();
		int keyFile = consoleIO.keyFileWithLock();
		string lockFilePath = consoleIO.inputFilePath(LOCK);
		string keyFilePath;
		if(keyFile == 1)
		 keyFilePath = consoleIO.inputFilePath(KEY);


		std::cout << "\n----------------------------------------------------------------------------\n\n";

		solve.generateRoots(safes, h, rootGen, noOfS, locksPerSafe, bonus);

		noOfS = consoleIO.confirmAmount(safes);

		if (noOfS < (int)safes.size()) {
			for (int i = noOfS; i < (int)safes.size(); ++i) {
				delete safes[i];
			}
			safes.resize(noOfS);
		}

		consoleIO.outputMultiSafeSolutions(safes);

		io.printLockFile(LOCKDIR + lockFilePath, safes);
		if(keyFile == 1)
			io.printKeyFile(KEYDIR + keyFilePath, h, safes);


	}
	else if (5 == mode) {
		string lockFilePath = consoleIO.inputFilePath(LOCK);
		string keyFilePath = consoleIO.inputFilePath(KEY);
		string multiSafePath = consoleIO.inputFilePath(MULTI);
		int locksPerSafe = consoleIO.inputNoOfLocks();
		int bonus = consoleIO.bonusValidation();


		io.readInLockFile(LOCKDIR + lockFilePath, safes, locksPerSafe);

		bool valid = solve.solveLocks(safes, h, bonus, locksPerSafe);


		if (valid) {
			consoleIO.outputLockSolution(h, safes);

			io.printKeyFile(KEYDIR + keyFilePath, h, safes);
			io.printMultiSafeFile(MULTIDIR + multiSafePath, safes);
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