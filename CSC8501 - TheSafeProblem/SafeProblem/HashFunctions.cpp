#include "HashFunctions.h"



HashFunctions::HashFunctions()
{
	UHF.insert(rand() % 19 - 9);
	UHF.insert(rand() % 19 - 9); 
	UHF.insert(rand() % 19 - 9);
	UHF.insert(rand() % 19 - 9);


	LHF.insert(rand() % 19 - 9);
	LHF.insert(rand() % 19 - 9);
	LHF.insert(rand() % 19 - 9);
	LHF.insert(rand() % 19 - 9);


	PHF.insert(rand() % 19 - 9);
	PHF.insert(rand() % 19 - 9);
	PHF.insert(rand() % 19 - 9);
	PHF.insert(rand() % 19 - 9);

	std::cout << "UHF (Hash Func Class): ";
	for (int i = 0; i < 4; ++i)
		std::cout << UHF.getAt(i);
	std::cout << std::endl;	

	std::cout << "LHF (Hash Func Class): ";
	for (int i = 0; i < 4; ++i)
		std::cout << LHF.getAt(i);
	std::cout << std::endl;

	std::cout << "PHF (Hash Func Class): ";
	for (int i = 0; i < 4; ++i)
		std::cout << PHF.getAt(i);
	std::cout << std::endl;

}

HashFunctions::HashFunctions(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4])
{
	for(int i = 0; i < 4; ++i)
	{
		this->UHF.insert(UHF[i]);
		this->LHF.insert(LHF[i]);
		this->PHF.insert(PHF[i]);
	}
}




HashFunctions::~HashFunctions()
{
}

void HashFunctions::hashRoot(Vec<Dial, 4>& Root)
{
	Vec<Dial, 4> testCN;

	for (int i = 0; i < 4; ++i)
		testCN.insert(Root.getAt(i) + UHF.getAt(i));

	std::cout << testCN.getAt(0).getEntry()
		<< testCN.getAt(1).getEntry()
		<< testCN.getAt(2).getEntry()
		<< testCN.getAt(3).getEntry()
		<< std::endl;
}
