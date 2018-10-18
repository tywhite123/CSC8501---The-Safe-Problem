#include"Lock.h"
#include<cstdlib>
#pragma once
class HashFunctions
{
public:
	HashFunctions();
	~HashFunctions();

	void hashRoot(Vec<Dial, 4>& Root);



private:
	Vec<int, 4> UHF;
	Vec<int, 4> LHF;
	Vec<int, 4> PHF;
};

