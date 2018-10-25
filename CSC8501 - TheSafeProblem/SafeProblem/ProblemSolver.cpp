#include "ProblemSolver.h"



ProblemSolver::ProblemSolver()
{
}


ProblemSolver::~ProblemSolver()
{
}



void ProblemSolver::generateRoots(vector<Safe*>& safes, HashFunctions *& h, int rootGen, int noOfSolutions, int noOfLocks, int bonus)
{


	int validSolutions = 0;
	
	HashFunctions* test;

	while (validSolutions < noOfSolutions) {

		validSolutions = 0;
		
		safes.clear();
		int iterations = 0;
		test = new HashFunctions();
		int i = 0;

		while (iterations < 10000) {
			bool isValid = true;

			int a, b, c, d;

			if (1 == rootGen) {
				a = rand() % 10;
				b = rand() % 10;
				c = rand() % 10;
				d = rand() % 10;
			}
			else {
				d = i % 10;
				c = i % 100 / 10;
				b = i % 1000 / 100;
				a = i / 1000;
			}


			Safe* s = new Safe(a, b, c, d, noOfLocks);

			//MULTI LOCK SAFE

			for (int j = 0; j < s->size() && isValid; ++j) {
				Vec<Dial, 4>* Root = s->getCurrentLock()->getLock();
				Vec<Dial, 4>* CNHash = s->getCurrentLock()->getCN();
				Vec<Dial, 4>* LNHash = s->getCurrentLock()->getLN();
				Vec<Dial, 4>* HNHash = s->getCurrentLock()->getHN();

				isValid = test->hashRoot(Root, CNHash, LNHash, HNHash);




				if (j < s->size() - 1) {
					s->nextLockRoot();
				}


			}

			if (isValid && bonus == 2) isValid = bonusCheck(s);

			if (isValid) {
				validSolutions++;
				safes.push_back(s);

			}
			else {
				delete s;
				s = nullptr;
			}
			if (2 == rootGen)
				i++;

			

			iterations++;

		}
		
		
		if (validSolutions < noOfSolutions) {
			delete test;
			test = nullptr;
			for (int t = 0; t < (int)safes.size(); ++t) {
				delete safes[t];
				safes[t] = nullptr;
			}
		}
		else {
			h = test;
		}
		
		if(validSolutions > 0)
			cout << "Valid Solutions: " << validSolutions << endl;
	}

	
	

}

void ProblemSolver::solveRoots(vector<Safe*>& safes, HashFunctions *& h)
{

	for (unsigned int i = 0; i < safes.size(); ++i) {
		bool isValid = true;
		for (int j = 0; j < safes[i]->size(); ++j) {
			Vec<Dial, 4>* Root = safes[i]->getCurrentLock()->getLock();
			Vec<Dial, 4>* CNHash = safes[i]->getCurrentLock()->getCN();
			Vec<Dial, 4>* LNHash = safes[i]->getCurrentLock()->getLN();
			Vec<Dial, 4>* HNHash = safes[i]->getCurrentLock()->getHN();

			isValid = h->hashRoot(Root, CNHash, LNHash, HNHash);


			


			if (j < 4) {
				safes[i]->nextLockRoot();
			}
		}
	}

}

bool ProblemSolver::solveLocks(vector<Safe*>& safes, HashFunctions *& h, int bonus)
{
	int combinedHF[4];
	int uhfAndLhf[4];
	int phf[4];
	int uhf[4];
	int lhf[4];

	vector<Vec<Dial,4>> testCNs;
	vector<vector<int>> candidateUHFs;


	for (int i = 0; i < 4; ++i) {
		combinedHF[i] =
			safes[0]->getLockAt(1)->getLN()->getAt(i).getEntry() -
			safes[0]->getLockAt(0)->getLN()->getAt(i).getEntry();
	}

	for (int i = 0; i < 4; ++i) {
		uhfAndLhf[i] =
			safes[0]->getLockAt(0)->getLN()->getAt(i).getEntry()-
			safes[0]->getLockAt(0)->getLock()->getAt(i).getEntry();
	}


	for (int i = 0; i < 4; ++i) {
		phf[i] = combinedHF[i] - uhfAndLhf[i];
	}



	for (unsigned int i = 0; i < safes.size(); ++i) {
		for (int j = 0; j < safes[i]->size(); ++j) {
			for (int k = 0; k < 4; ++k) {
				int test = (safes[i]->getLockAt(j)->getLN()->getAt(k).getEntry() + phf[k]) % 10;
				if (test < 0)
					test = 10 + test;
				safes[i]->getLockAt(j)->getHN()->insert(test);
			}

			

		}
		
	}
/*
	bool finished = false;
	while (!finished) {*/


		bool valid = true;
		int t = 0;
		while (/*valid && *//*!finished &&*/ t < 10000) {
			uhf[3] =  t % 10;
			uhf[2] =  t % 100 / 10;
			uhf[1] =  t % 1000 / 100;
			uhf[0] =  t / 1000;

			

			for (int i = 0; i < (int)safes.size(); ++i) {
				for (int j = 0; j < safes[i]->size(); ++j) {
					Vec<Dial, 4> cn;
					for (int k = 0; k < 4; ++k) {
						if (j == 0) 
							cn.insert((safes[i]->getLockAt(j)->getLock()->getAt(k).getEntry() + uhf[k]) % 10);
						else
							cn.insert((safes[i]->getLockAt(j-1)->getHN()->getAt(k).getEntry() + uhf[k]) % 10);
					}
					testCNs.push_back(cn);
				}
			}

			for (int i = 0; i < (int)testCNs.size(); ++i) {
				for (int k = 0; k < 3; ++k) {
					for (int j = k + 1; j < 4; ++j) {
						if (testCNs[i].getAt(k).getEntry() == testCNs[i].getAt(j).getEntry()) {
							valid = false;
						}
					}
				}
			}

			if (valid && bonus == 2) {
				for (int i = 0; i < (int)testCNs.size() && valid; ++i) {
					int left = 0;
					int right = 0;

					if (i % safes[i]->size() == safes[i]->size()-1)
						continue;

					for (int j = 0; j < 4; ++j) {
						left += testCNs[i].getAt(j).getEntry();
						right += testCNs[i + 1].getAt(j).getEntry();
					}

					if (left < right)
						valid = true;
					else
						valid = false;

				}

				if (valid) {
					int total = 0;
					for (int i = 0; i < (int)testCNs.size() && valid; ++i) {
						for (int j = 0; j < 4; ++j)
							total += testCNs[i].getAt(j).getEntry();
					}

					if (total % 2 == 0)
						valid = true;
					else
						valid = false;
				}
			}

			if (valid) {
				vector<int> uhfToEnter;
				for (int i = 0; i < 4; ++i)
					uhfToEnter.push_back(uhf[i]);
				candidateUHFs.push_back(uhfToEnter);
			}
			else {
				testCNs.clear();
				valid = true;
				
			}
			++t;

		}

		if (candidateUHFs.size() <= 0)
			valid = false;

	//}

		if (valid) {

			if (candidateUHFs.size() > 1) {
				int selected = io.confirmCandidateUHF(candidateUHFs);
				for (int i = 0; i < 4; ++i)
					uhf[i] = candidateUHFs[selected].at(i);
			}
			else {
				for (int i = 0; i < 4; ++i)
					uhf[i] = candidateUHFs[0].at(i);
			}


			testCNs.clear();
			for (int i = 0; i < (int)safes.size(); ++i) {
				for (int j = 0; j < safes[i]->size(); ++j) {
					Vec<Dial, 4> cn;
					for (int k = 0; k < 4; ++k) {
						if (j == 0)
							cn.insert((safes[i]->getLockAt(j)->getLock()->getAt(k).getEntry() + uhf[k]) % 10);
						else
							cn.insert((safes[i]->getLockAt(j - 1)->getHN()->getAt(k).getEntry() + uhf[k]) % 10);
					}
					testCNs.push_back(cn);
				}
			}

			for (int i = 0; i < (int)safes.size(); ++i) {
				for (int j = i * safes[i]->size(); j < (i * safes[i]->size()) + safes[i]->size(); ++j) {
					for (int k = 0; k < 4; ++k)
						safes[i]->getLockAt(j % safes[i]->size())->getCN()->insert(Dial(testCNs[j].getAt(k).getEntry()));
				}
			}


			for (int i = 0; i < 4; ++i) {
				lhf[i] = (uhfAndLhf[i] - uhf[i]) % 10;
			}

			h = new HashFunctions(uhf, lhf, phf);
		}

		return valid;
}

bool ProblemSolver::bonusCheck(Safe *& s)
{
	bool valid = true;
	for (int i = 0; i < 4 && valid; ++i) {
		int left = 0;
		int right = 0;

		for (int j = 0; j < 4; ++j) {
			left += s->getLockAt(i)->getCN()->getAt(j).getEntry();
			right += s->getLockAt(i+1)->getCN()->getAt(j).getEntry();
		}

		if (left < right)
			valid = true;
		else
			valid = false;

	}

	if (valid) {
		int total = 0;
		for (int i = 0; i < s->size() && valid; ++i) {
			for (int j = 0; j < 4; ++j)
				total += s->getLockAt(i)->getCN()->getAt(j).getEntry();
		}

		if (total % 2 == 0)
			valid = true;
		else
			valid = false;
	}




	return valid;
	
}
