#pragma once

#include<vector>
#include <string>
#include "Path.h"
//#include "Network.h"
using namespace::std;

class Way_Calculator
{
protected:
	City* start;
	City* ende;
	vector<Path> waysFound;		// potential memory leak

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	//Way_Calculator();

	// Default Deconstructor
	~Way_Calculator();
};

