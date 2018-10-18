
#include"Lock.h"
#pragma once
class HashFunctions
{
public:
	HashFunctions();
	HashFunctions(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]);
	~HashFunctions();

	void hashRoot(Vec<Dial, 4>& Root);



private:
	Vec<int, 4> UHF;
	Vec<int, 4> LHF;
	Vec<int, 4> PHF;
};

