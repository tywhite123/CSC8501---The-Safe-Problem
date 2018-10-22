#include "FileIO.h"



FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}

void FileIO::printKeyFile(string filepath, HashFunctions & h, vector<Safe*>& validSafe)
{
	std::ofstream keyFile(filepath);

	if (keyFile) {
		keyFile << "NS " << validSafe.size() << std::endl;

		for (int i = 0; i < validSafe.size(); ++i)
		{
			keyFile << "ROOT " << validSafe[i]->getLockAt(0)->getLock()->getAt(0).getEntry()
				<< validSafe[i]->getLockAt(0)->getLock()->getAt(1).getEntry()
				<< validSafe[i]->getLockAt(0)->getLock()->getAt(2).getEntry()
				<< validSafe[i]->getLockAt(0)->getLock()->getAt(3).getEntry() << std::endl;

			keyFile << "UHF " << h.getUHF().getAt(0) << ","
				<< h.getUHF().getAt(1) << ","
				<< h.getUHF().getAt(2) << ","
				<< h.getUHF().getAt(3) << std::endl;

			keyFile << "LHF " << h.getLHF().getAt(0) << ","
				<< h.getLHF().getAt(1) << ","
				<< h.getLHF().getAt(2) << ","
				<< h.getLHF().getAt(3) << std::endl;

			keyFile << "PHF " << h.getPHF().getAt(0) << ","
				<< h.getPHF().getAt(1) << ","
				<< h.getPHF().getAt(2) << ","
				<< h.getPHF().getAt(3) << std::endl;
		}
	}

	keyFile.close();

}

void FileIO::printMultiSafeFile(string filepath, vector<Safe*>& safes)
{
	std::ofstream multiSafeFile(filepath);


	if (multiSafeFile) {
		multiSafeFile << "NS " << safes.size() << std::endl;

		for(int i = 0; i < safes.size(); ++i)
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

void FileIO::readInKeyFile(string filepath, HashFunctions & h, vector<Safe*>& safes)
{
	//TODO: REGEX FOR READING A KEY FILE
	//[0-9]+|[0-9 ]+ (For reading root)
	//



}