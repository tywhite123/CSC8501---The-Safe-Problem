#include "Safe.h"
#include"HashFunctions.h"
#include <vector>
#include <string>

#pragma once

using namespace std;

class ConsoleIO
{
public:
	ConsoleIO();
	~ConsoleIO();

	int selectMode();
	int selectRandom();
	int inputNoOfSolutions();
	string inputFilePath();
	int confirmAmount(vector<Safe*>&safes);
	int inputNoOfLocks();
	int bonusValidation();

	int confirmCandidateUHF(vector<vector<int>> candidateUHF);
	void nothingFound();

	void outputHashFunctions(HashFunctions *&h, int solutions);
	void outputMultiSafeSolutions(vector<Safe*>& safes);
	void outputLockSolution(HashFunctions*& h, vector<Safe*>&safes);


	void endOfProgram();


};

