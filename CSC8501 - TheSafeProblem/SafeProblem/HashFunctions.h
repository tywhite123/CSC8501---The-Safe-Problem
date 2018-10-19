
#include"Lock.h"
#pragma once
class HashFunctions
{
public:
	HashFunctions();
	HashFunctions(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4]);
	~HashFunctions();

	bool hashRoot(Vec<Dial, 4>& Root, Vec<Dial, 4>*&CN, Vec<Dial, 4>*&LN, Vec<Dial, 4>*&HN);



private:
	Vec<int, 4> UHF;
	Vec<int, 4> LHF;
	Vec<int, 4> PHF;
};

