#pragma once
#include<vector>
#include "Safe.h"
#include "HashFunctions.h"
#include "ConsoleIO.h"

using namespace std;

class ProblemSolver
{
public:
	ProblemSolver();
	~ProblemSolver();


	void generateRoots(vector<Safe*>& safes, HashFunctions*& h, int rootGen, int noOfSolutions);

	void solveRoots(vector<Safe*>& safes, HashFunctions*& h);

	bool solveLocks(vector<Safe*>& safes, HashFunctions*& h);

	bool bonusCheck(Safe *&s);


private :
	ConsoleIO io;
};

