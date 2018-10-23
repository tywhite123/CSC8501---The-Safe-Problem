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



	void outputHashFunctions(HashFunctions &h, int solutions);
	void outputMultiSafeSolutions(vector<Safe*>& safes);

};

