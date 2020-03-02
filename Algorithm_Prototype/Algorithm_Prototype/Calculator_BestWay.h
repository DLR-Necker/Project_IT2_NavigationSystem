#pragma once

#include "Way_Calculator.h"

class Calculator_BestWay :
	protected Way_Calculator
{
protected:
	vector<vector<int>> waysFound;
	unsigned int cost_bestWay;

public:
	// Default Constructor
	Calculator_BestWay();
	
	// Default Deconstructor
	~Calculator_BestWay();


};


