#pragma once
#include<vector>
#include "Safe.h"
#include "HashFunctions.h"

using namespace std;

class ProblemSolver
{
public:
	ProblemSolver();
	~ProblemSolver();

	void generateRoots(vector<Safe*>& safes, HashFunctions &h, int rootGen, int noOfSolutions);

	void solveRoots(vector<Safe*>& safes, HashFunctions*& h);



};

