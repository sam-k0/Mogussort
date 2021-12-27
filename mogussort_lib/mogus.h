#pragma once
#include <vector>
#include <iostream>
using namespace std;

class mogus
{
private:
	vector<int>* inputVec;
	vector<int>* outputVec;

public:
	mogus() // Allocate vectors
	{
		inputVec = new vector<int>;
		outputVec = new vector<int>;
	}

	void addElement(int e);

	int getElement(int pos);

	void mogussort();

	void print();

	void printVec(vector<int>* vec);
};

