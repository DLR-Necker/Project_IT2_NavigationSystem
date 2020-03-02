#ifndef WAY_CALCULATOR_H
#define	WAY_CALCULATOR_H

#include<vector>
#include <string>
#include "City.h"
using namespace::std;

class Way_Calculator
{
protected:
	int network[100][100];
	Vertex start;
	Vertex ende;
<<<<<<< HEAD
	vector<vector<City*>> waysFound;		// potential memory leak :(
=======
	vector<vector<City*>> waysFound;
>>>>>>> f41afc77d19f88bc92aea49600dea939055e412d

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	Way_Calculator(int network[100][100]);

	// Default Deconstructor
	~Way_Calculator();
};
#endif
