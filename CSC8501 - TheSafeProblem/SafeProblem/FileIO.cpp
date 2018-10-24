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
			
			for(int j = 0; j < 5; ++j)
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
				<< safes[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
				<< safes[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
				<< safes[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

			for (int j = 0; j < 5; ++j)
			{
				lockFile << "LN" << j << ": ";
				for (int k = 0; k < 4; ++k)
					lockFile << safes[i]->getLockAt(j)->getLN()->getAt(k).getEntry() << " ";
				lockFile << endl;
			}

			lockFile << endl;

		}


	}

	lockFile.close();


}

void FileIO::readInKeyFile(string filepath, HashFunctions *& h, vector<Safe*>& safes)
{
	//TODO: REGEX FOR READING A KEY FILE
	//[0-9]+|[0-9 ]+ (For reading root)
	//((\+|-)?[0-9]+, ?){3}(\+|-)?[0-9]+ (For reading hash functions)

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

							//TODO: ADD VALUES TO THE CORRECT VECTOR

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
				//TODO: THROW EXCEPTION
			}

		}
	}

	keyFile.close();


}

void FileIO::readInLockFile(string filepath, vector<Safe*>& safes)
{
	regex root("(ROOT:) [0-9]+|[0-9 ]+");
	regex lock("(LN[0-9]: )([0-9] ?)+");

	fstream lockFile(filepath);


	if (lockFile) {
		string line;
		bool hashEntered = false;
		int currentSafe = 0;

		while (getline(lockFile, line)) {

			int a, b, c, d;

			if (regex_match(line, root)) {

				stringstream split(line);
				while (split.good()) {
					string substr;
					getline(split, substr, ' ');
					if (substr != "ROOT:") {
						int value = stoi(substr);

						d = value % 10;
						c = value / 10 % 10;
						b = value / 100 % 10;
						a = value / 1000 % 10;

						safes.push_back(new Safe(a, b, c, d));

					}

				}

			}
			else if (regex_match(line, lock)) {
				stringstream split(line);
				while (split.good()) {
					string substr;
					getline(split, substr, ' ');
					if (substr != "LN0:" && substr != "LN1:" && substr != "LN2:" && substr != "LN3:" && substr != "LN4:") {
						int value = stoi(substr);
						safes[currentSafe]->getCurrentLock()->getLN()->insert(Dial(value));
					}

				}
				
				

				if (safes[currentSafe]->whichLock() >= 4)
					++currentSafe;
				else
					safes[currentSafe]->nextLock();
				

			}

			
			
			

		}


	}

	lockFile.close();



}
