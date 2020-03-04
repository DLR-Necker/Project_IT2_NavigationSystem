#pragma once

#include<vector>
#include <string>
#include "Path.h"
#include "Vertex.h"
#include "Network.h"
using namespace::std;

class Way_Calculator
{
protected:
	Vertex start;
	Vertex ende;
	vector<Path> waysFound;

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	//Way_Calculator();

	// Default Deconstructor
	~Way_Calculator();
};

