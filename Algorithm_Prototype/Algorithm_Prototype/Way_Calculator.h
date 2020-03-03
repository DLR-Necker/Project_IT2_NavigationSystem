#pragma once

#include<vector>
#include <string>
#include "Map.h"
#include "Vertex.h"
#include "Path.h"
using namespace::std;

class Way_Calculator
{
protected:
	unsigned int network_distance[maxCitys][maxCitys];
	unsigned int network_time[maxCitys][maxCitys];
	City* start;
	City* ende;
	vector<Path> waysFound;		// potential memory leak

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	Way_Calculator(int network_distance[maxCitys][maxCitys], unsigned int network_time[maxCitys][maxCitys]);

	// Default Deconstructor
	~Way_Calculator();
};

