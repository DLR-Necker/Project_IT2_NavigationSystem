#pragma once

#include<vector>
#include <string>
#include "Map.h"
#include "Vertex.h"
using namespace::std;

class Way_Calculator
{
protected:
	int network[maxCitys][maxCitys];
	Vertex start;
	Vertex ende;
	vector<vector<City*>> waysFound;		// potential memory leak :(

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	Way_Calculator(int network[maxCitys][maxCitys]);

	// Default Deconstructor
	~Way_Calculator();
};

