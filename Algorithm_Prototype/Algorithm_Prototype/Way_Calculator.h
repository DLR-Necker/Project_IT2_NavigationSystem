#pragma once

#include<vector>
#include <string>
#include "Path.h"
using namespace::std;

class Way_Calculator
{
protected:
	int start;
	int ende;
	vector<Path> waysFound;


public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	//Way_Calculator();

	// Default Deconstructor
	~Way_Calculator();
};

