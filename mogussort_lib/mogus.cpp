#include "pch.h"
#include "mogus.h"
#include <cstdlib>

using namespace std;

void mogus::addElement(int e)
{
	inputVec->push_back(e);
}

int mogus::getElement(int pos)
{
	if (pos > outputVec->size())
	{
		return outputVec->at(pos);
	}
	std::cout << "Accessing element out of vector " << endl;
	return -1;
}

void mogus::mogussort()
{
	int iterCount = 0;
	int loopCount = 0;
	outputVec->clear();
	// Copy to temp
	vector<int>* tempInput = new vector<int>;
	for (int element : *inputVec)
	{
		tempInput->push_back(element);
	}
	bool sorted = false;
	int votedMate;

	while (!sorted)
	{
		iterCount++;														// Add to loop count 
		int randpos = 0;													// Choose random position	
		//if(tempInput->size() > 1)
		//{ 
		randpos = std::rand() % (int)tempInput->size();
		//}
		//cout << "Choosing crewmate at " << randpos << " of " << tempInput->size() - 1 << endl;
		
		/* Vote sussy crewmates */
		votedMate = tempInput->at(randpos);									// Get the random impostor
		tempInput->erase(tempInput->begin() + randpos);						// Remove from Crewmates
		outputVec->push_back(votedMate);									// add to alleged impostor list
		/* Check if imposters are REALLY SUS? */
		
		int prev = -INFINITY;
		for (int i = 0; i < outputVec->size(); i++)
		{
			if (prev > outputVec->at(i))
			{
				// Sussy?
				//cout << "Imposter won! " << prev << " was the imposter. " << outputVec->at(i) << " lost." << endl;
				// Reset the temp vec
				tempInput->clear();
				for (int element : *inputVec)
				{
					tempInput->push_back(element);
				}
				outputVec->clear();
				sorted = false;
				loopCount++;
				break;
			}
			prev = outputVec->at(i);
		}

		// Show things
		//std::cout << "Showing tempInput: " << std::endl;
		//printVec(tempInput);
		//std::cout << "Showing output: " << std::endl;
		//printVec(outputVec);

		if (tempInput->empty())
		{
			sorted = true;
		}
	}

	delete tempInput; // NO MEMORY LEAKS >:(
	cout << "Finished sorting " << inputVec->size() << " elements in " << iterCount << " iterations ("<<loopCount<< " loops)" << endl;
}

void mogus::print()
{
	std::cout << "Printing output:" << std::endl;
	for (int e : *outputVec)
	{
		std::cout << e << ",";
	}
	std::cout << std::endl;
}

void mogus::printVec(vector<int>* vec)
{
	for (int e : *vec)
	{
		std::cout << e << ",";
	}
	std::cout << std::endl;
}
