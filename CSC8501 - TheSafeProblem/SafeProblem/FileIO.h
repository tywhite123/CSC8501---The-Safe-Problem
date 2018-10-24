#pragma once

#include"HashFunctions.h"
#include"Safe.h"
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class FileIO
{
public:
	FileIO();
	~FileIO();

	void printKeyFile(string filepath, HashFunctions*& h, vector<Safe*>& safes);
	void printMultiSafeFile(string filepath, vector<Safe*>& safes);
	void printLockFile(string filepath, vector<Safe*>& safes);

	void readInKeyFile(string filepath, HashFunctions *&h, vector<Safe*>& safes);
	void readInLockFile(string filepath, vector<Safe*>& safes);



};

