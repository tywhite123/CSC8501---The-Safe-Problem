#include "ProblemSolver.h"



ProblemSolver::ProblemSolver()
{
}


ProblemSolver::~ProblemSolver()
{
}

void ProblemSolver::generateRoots(vector<Safe*>& safes, HashFunctions & h, int rootGen, int noOfSolutions)
{

	int validSolutions = 0;
	int i = 0;
	int iterations = 0;

	while (validSolutions < noOfSolutions && iterations < 10000) {
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


		Safe* s = new Safe(a, b, c, d);

		//MULTI LOCK SAFE

		for (int j = 0; j < 5 && isValid; ++j) {
			Vec<Dial, 4>* Root = s->getCurrentLock()->getLock();
			Vec<Dial, 4>* CNHash = s->getCurrentLock()->getCN();
			Vec<Dial, 4>* LNHash = s->getCurrentLock()->getLN();
			Vec<Dial, 4>* HNHash = s->getCurrentLock()->getHN();

			isValid = h.hashRoot(Root, CNHash, LNHash, HNHash);



			if (j < 4) {
				s->nextLockRoot();
			}


		}

		if (isValid) {
			validSolutions++;
			safes.push_back(s);

		}
		if (2 == rootGen)
			i++;

		iterations++;

	}


	

}

void ProblemSolver::solveRoots(vector<Safe*>& safes, HashFunctions *& h)
{

	for (unsigned int i = 0; i < safes.size(); ++i) {
		bool isValid = true;
		for (int j = 0; j < 5; ++j) {
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
