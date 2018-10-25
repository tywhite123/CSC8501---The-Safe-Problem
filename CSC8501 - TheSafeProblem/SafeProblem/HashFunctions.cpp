#include "HashFunctions.h"



HashFunctions::HashFunctions()
{

	//Randomly generate each hash function
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

}

HashFunctions::HashFunctions(int(&UHF)[4], int(&LHF)[4], int(&PHF)[4])
{
	//inserts the data if using this constructor
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

	//hashes each value
	
	for (int i = 0; i < 4; ++i)
		CN->insert(Root->getAt(i) + UHF.getAt(i));

	//regular validation to check no repeating numbers
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (CN->getAt(i).getEntry() == CN->getAt(j).getEntry()) {
				validCN = false;
			}
		}
	}

	for (int i = 0; i < 4; ++i)
		LN->insert(CN->getAt(i) + LHF.getAt(i));
	
	for (int i = 0; i < 4; ++i)
		HN->insert(LN->getAt(i) + PHF.getAt(i));

	return validCN;

}


