#include "ConsoleIO.h"



ConsoleIO::ConsoleIO()
{
}


ConsoleIO::~ConsoleIO()
{
}

int ConsoleIO::selectMode()
{
	int selected;

	cout
		<< "1. Generate Key File\n"
		<< "2. Generate Multi Safe File\n"
		<< "3. Generate Key and Multi Safe Files\n"
		<< "4. Generate Lock File\n"
		<< "5. Read Lock File\n"
		<< "6. Exit\n";

	cin >> selected;


	return selected;



}

int ConsoleIO::selectRandom()
{
	int selected;
	
	cout
		<< "Select how you want roots to be generated: \n"
		<< "1. Completely Random Roots\n"
		<< "2. Check from 0000 - 9999\n";

	cin >> selected;

	return selected;
}

int ConsoleIO::inputNoOfSolutions()
{
	int noOfS = 0;
	bool validAnswer = false;

	
	cout << "Please enter the amount of solutions you want: ";
	while (!validAnswer) {
		cin >> noOfS;

		if (noOfS > 0) validAnswer = true;
	}


	return noOfS;
}

string ConsoleIO::inputFilePath()
{	
	string filepath;

	cout << "Please Enter the Filepath: ";
	/*getline(cin, filepath);
*/

	cin >> filepath;
	return filepath;
}

int ConsoleIO::confirmAmount(vector<Safe*>& safes)
{
	cout << "Found " << safes.size() << " solutions, how many do you want?" << endl;
	
	int amount = 0;

	while(amount <= 0 || amount > (int)safes.size())
		cin >> amount;

	return amount;
}

int ConsoleIO::inputNoOfLocks()
{
	int noOfLocks = 0;
	bool validAnswer = false;


	cout << "Please enter the amount of locks you want per safe: ";
	while (!validAnswer) {
		cin >> noOfLocks;

		if (noOfLocks > 0) validAnswer = true;
	}


	return noOfLocks;
}

int ConsoleIO::confirmCandidateUHF(vector<vector<int>> candidateUHF)
{
	cout << "Total Candidate UHFs: " << candidateUHF.size() << endl;
	cout << "Candidate UHFs: " << endl;
	for (unsigned int i = 0; i < candidateUHF.size(); ++i) {
		cout << i+1 << ":";
		for (int j = 0; j < 4; ++j) {
			cout << " " << candidateUHF[i].at(j);
		}
		cout << endl;
	}
	
	cout << "Please select a UHF to try: " << endl;

	int selected = 0;
	while (selected <= 0 || selected > (int)candidateUHF.size())
		cin >> selected;


	return selected - 1;
}

void ConsoleIO::nothingFound()
{
	cout << "No valid solutions found for that file" << endl;
}

void ConsoleIO::outputHashFunctions(HashFunctions *& h, int solutions)
{
	cout << "UHF:\t" << h->getUHF().getAt(0) << ", " << h->getUHF().getAt(1) << ", " << h->getUHF().getAt(2) << ", " << h->getUHF().getAt(3) << endl;
	cout << "LHF:\t" << h->getLHF().getAt(0) << ", " << h->getLHF().getAt(1) << ", " << h->getLHF().getAt(2) << ", " << h->getLHF().getAt(3) << endl;
	cout << "PHF:\t" << h->getPHF().getAt(0) << ", " << h->getPHF().getAt(1) << ", " << h->getPHF().getAt(2) << ", " << h->getPHF().getAt(3) << endl;

	cout << "Number of Solutions found with this Hash: " << solutions << endl;

}

void ConsoleIO::outputMultiSafeSolutions(vector<Safe*>& safes)
{

	for (unsigned int i = 0; i < safes.size(); ++i) {
		std::cout << "\tSolution " << i + 1 << std::endl << std::endl;

		std::cout << "\tROOT:\t" << safes[i]->getLockAt(0)->getLock()->getAt(0).getEntry()
			<< safes[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
			<< safes[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
			<< safes[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

		for (int j = 0; j < safes[i]->size(); ++j) {
			std::cout << "\tCN" << j << ":";
			for (int k = 0; k < 4; k++)
				std::cout << safes[i]->getLockAt(j)->getCN()->getAt(k).getEntry();
			std::cout << "\t"; //<< std::endl;

			std::cout << "LN" << j << ":";
			for (int k = 0; k < 4; k++)
				std::cout << safes[i]->getLockAt(j)->getLN()->getAt(k).getEntry();
			std::cout << "\t"; //<< std::endl;

			std::cout << "HN" << j << ":";
			for (int k = 0; k < 4; k++)
				std::cout << safes[i]->getLockAt(j)->getHN()->getAt(k).getEntry();
			std::cout << std::endl;
		}



		std::cout << "\n----------------------------------------------------------------------------\n\n";

	}



	std::cout << "Total Number of Solutions: " << safes.size();

}

void ConsoleIO::outputLockSolution(HashFunctions *& h, vector<Safe*>& safes)
{

	cout << "UHF:\t" << h->getUHF().getAt(0) << ", " << h->getUHF().getAt(1) << ", " << h->getUHF().getAt(2) << ", " << h->getUHF().getAt(3) << endl;
	cout << "LHF:\t" << h->getLHF().getAt(0) << ", " << h->getLHF().getAt(1) << ", " << h->getLHF().getAt(2) << ", " << h->getLHF().getAt(3) << endl;
	cout << "PHF:\t" << h->getPHF().getAt(0) << ", " << h->getPHF().getAt(1) << ", " << h->getPHF().getAt(2) << ", " << h->getPHF().getAt(3) << endl;

	cout << "Number of Solutions found with this Hash: " << safes.size() << endl;
}

void ConsoleIO::endOfProgram()
{
	std::cout << "\n----------------------------------------------------------------------------\n\n";
	
	cout << "Please Enter Something to exit" << endl;

	int exit;
	cin >> exit;
}
