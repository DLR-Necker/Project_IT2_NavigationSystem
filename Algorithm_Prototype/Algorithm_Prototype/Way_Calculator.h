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
	vector<vector<City*>> waysFound;

public:
	// Default Constructor
	Way_Calculator();

	// Special Constructor
	Way_Calculator(int network[100][100]);

	// Default Deconstructor
	~Way_Calculator();
};
#endif
