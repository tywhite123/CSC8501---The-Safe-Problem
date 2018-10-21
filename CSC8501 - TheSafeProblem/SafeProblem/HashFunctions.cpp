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

bool HashFunctions::hashRoot(Vec<Dial, 4>*& Root, Vec<Dial, 4>*&CN, Vec<Dial, 4>*&LN, Vec<Dial, 4>*&HN)
{

	bool validCN = true;
	
	for (int i = 0; i < 4; ++i)
		CN->insert(Root->getAt(i) + UHF.getAt(i));

	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (CN->getAt(i).getEntry() == CN->getAt(j).getEntry()) {
				validCN = false;
			}
		}
	}

	/*std::cout << CN.getAt(0).getEntry()
		<< CN.getAt(1).getEntry()
		<< CN.getAt(2).getEntry()
		<< CN.getAt(3).getEntry()
		<<  " ";*/

	for (int i = 0; i < 4; ++i)
		LN->insert(CN->getAt(i) + LHF.getAt(i));
	
	for (int i = 0; i < 4; ++i)
		HN->insert(LN->getAt(i) + PHF.getAt(i));

	return validCN;

}


