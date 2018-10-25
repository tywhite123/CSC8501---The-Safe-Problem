#include "FileIO.h"
#include <regex>
#include<sstream>



FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

void FileIO::printKeyFile(string filepath, HashFunctions *& h, vector<Safe*>& validSafe)
{
	std::ofstream keyFile(filepath);

	if (keyFile) {
		keyFile << "NS " << validSafe.size() << std::endl;

		for (unsigned int i = 0; i < validSafe.size(); ++i)
		{
			keyFile << "ROOT " << validSafe[i]->getLockAt(0)->getLock()->getAt(0).getEntry()
				<< validSafe[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
				<< validSafe[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
				<< validSafe[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

			keyFile << "UHF " << h->getUHF().getAt(0) << ","
				<< h->getUHF().getAt(1) << ","
				<< h->getUHF().getAt(2) << ","
				<< h->getUHF().getAt(3) << std::endl;

			keyFile << "LHF " << h->getLHF().getAt(0) << ","
				<< h->getLHF().getAt(1) << ","
				<< h->getLHF().getAt(2) << ","
				<< h->getLHF().getAt(3) << std::endl;

			keyFile << "PHF " << h->getPHF().getAt(0) << ","
				<< h->getPHF().getAt(1) << ","
				<< h->getPHF().getAt(2) << ","
				<< h->getPHF().getAt(3) << std::endl;
		}
	}

	keyFile.close();

}

void FileIO::printMultiSafeFile(string filepath, vector<Safe*>& safes)
{
	std::ofstream multiSafeFile(filepath);


	if (multiSafeFile) {
		multiSafeFile << "NS " << safes.size() << std::endl;

		for(unsigned int i = 0; i < safes.size(); ++i)
		{
			
			for(int j = 0; j < safes[i]->size(); ++j)
			{
				
				multiSafeFile << "CN" << j << " ";
				for (int k = 0; k < 4; ++k)
					multiSafeFile << safes[i]->getLockAt(j)->getCN()->getAt(k).getEntry();

				multiSafeFile << " ";


				multiSafeFile << "LN" << j << " ";
				for (int k = 0; k < 4; ++k)
					multiSafeFile << safes[i]->getLockAt(j)->getLN()->getAt(k).getEntry();

				multiSafeFile << " ";

				multiSafeFile << "HN" << j << " ";
				for (int k = 0; k < 4; ++k)
					multiSafeFile << safes[i]->getLockAt(j)->getHN()->getAt(k).getEntry();

				multiSafeFile << " ";

				multiSafeFile << std::endl;

			}

			multiSafeFile << std::endl;

		}

	}


	multiSafeFile.close();

}

void FileIO::printLockFile(string filepath, vector<Safe*>& safes)
{
	ofstream lockFile(filepath);

	if (lockFile) {
		lockFile << "NL " << safes.size() << std::endl;

		for (unsigned int i = 0; i < safes.size(); ++i)
		{

			lockFile << "ROOT: " << safes[i]->getLockAt(0)->getLock()->getAt(0).getEntry()
				<< " " << safes[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
				<< " " << safes[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
				<< " " << safes[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

			for (int j = 0; j < safes[i]->size(); ++j)
			{
				lockFile << "LN" << j << ":";
				for (int k = 0; k < 4; ++k)
					lockFile << " " << safes[i]->getLockAt(j)->getLN()->getAt(k).getEntry();
				lockFile << endl;
			}

			lockFile << endl;

		}


	}

	lockFile.close();


}

void FileIO::readInKeyFile(string filepath, HashFunctions *& h, vector<Safe*>& safes) throw (exception)
{
	//TODO: REGEX FOR READING A KEY FILE
	//[0-9]+|[0-9 ]+ (For reading root)
	//((\+|-)?[0-9]+, ?){3}(\+|-)?[0-9]+ (For reading hash functions)

	//Allows to check if the right format is used in the data file
	regex root("(ROOT) [0-9]+|[0-9 ]+");
	regex hash("(UHF|LHF|PHF) ((\\+|-)?[0-9]+, ?){3}(\\+|-)?[0-9]+");
	regex ns("(NS) ?[0-9]+");

	int UHF[4];
	int LHF[4];
	int PHF[4];
	bool uhfEntered = false;
	bool lhfEntered = false;
	bool phfEntered = false;

	//(UHF|LHF|PHF) ?

	fstream keyFile(filepath);

	if (keyFile) {
		string line;
		bool hashEntered = false;


		while (getline(keyFile, line)) {

			int a, b, c, d;

			if (regex_match(line, root)) {

				stringstream split(line);
				while (split.good()) {
					string substr;
					getline(split, substr, ' ');
					if (substr != "ROOT"){
						int value = stoi(substr);

						d = value % 10;
						c = value / 10 % 10;
						b = value / 100 % 10;
						a = value / 1000 % 10;

						safes.push_back(new Safe(a, b, c, d));

					}

				}
				
			}
			else if (regex_match(line, hash) && !hashEntered) {
				stringstream splitSpace(line);

				string type;

				while (splitSpace.good()) {
					int i = 0;
					string substr;
					getline(splitSpace, substr, ' ');
					if (substr != "UHF" && substr != "LHF" && substr != "PHF") {
						stringstream split(substr);
				
						while (split.good()) {
							string substrTwo;
							getline(split, substrTwo, ',');
							int value = stoi(substrTwo);
							
							if (type == "UHF") {
								UHF[i] = value;
								if (i == 3)
									uhfEntered = true;
							}
							else if (type == "LHF") {
								LHF[i] = value;
								if (i == 3)
									lhfEntered = true;
							}
							else if (type == "PHF") {
								PHF[i] = value;
								if (i == 3)
									phfEntered = true;
							}
							i++;

							if (uhfEntered && lhfEntered && phfEntered) {
								h = new HashFunctions(UHF, LHF, PHF);
								hashEntered = true;
							}


						}
					}
					else {
						type = substr;
					}

				}

				

				
			}
			else if (regex_match(line, ns)) {
			/*	stringstream split(line);
				while (split.good()) {
					string substr;
					getline(split, substr, ' ');
					if (substr != "NS") {

					}*/


			}
			else {
				if (!hashEntered) {

					//Delete all heap memory if allocated so it isnt stuck in memory
					for (int i = 0; i < (int)safes.size(); ++i)
						delete safes[i];
					if (h != nullptr)
						delete h;
					h = nullptr;

					//throw the exception
					throw exception("Not a valid file");
				}
				
			}

		}
	}

	keyFile.close();


}

void FileIO::readInLockFile(string filepath, vector<Safe*>& safes, int size)
{
	regex root("(ROOT:) ([0-9] ?)+");
	regex lock("(LN[0-9]: )([0-9] ?)+");
	regex amount("LN[0-9]:");

	fstream lockFile(filepath);

	if (lockFile) {
		string line;
		bool hashEntered = false;
		int currentSafe = 0;

		while (getline(lockFile, line)) {

			if (regex_match(line, root)) {

				stringstream split(line);
				int safeRoot[4];
				int i = 0;
				while (split.good()) {
					string substr;
					getline(split, substr, ' ');
					if (substr != "ROOT:") {
						int value = stoi(substr);

						safeRoot[i] = value;
						++i;

					}

				}
				safes.push_back(new Safe(safeRoot[0], safeRoot[1], safeRoot[2], safeRoot[3], size));

			}
			else if (regex_match(line, lock)) {
				stringstream split(line);
				while (split.good()) {
					string substr;
					getline(split, substr, ' ');
					if (!regex_match(substr, amount)) {
						int value = stoi(substr);
						safes[currentSafe]->getCurrentLock()->getLN()->insert(Dial(value));
					}

				}
				
				

				if (safes[currentSafe]->whichLock() >= size - 1)
					++currentSafe;
				else
					safes[currentSafe]->nextLock();
				

			}

			
			
			

		}


	}

	lockFile.close();



}
