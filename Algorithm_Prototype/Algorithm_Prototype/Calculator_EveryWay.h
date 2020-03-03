#pragma once
#include "Way_Calculator.h"
#include "Path.h"
#include "Map.h"
using namespace::std;


class Calculator_EveryWay :
	protected Way_Calculator
{
protected:
	vector<Path> possiblePaths;

public:
	// Default Constructor
	Calculator_EveryWay();

	// Default Deconstructor
	~Calculator_EveryWay();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	/*** Setter ***/
	void setPossiblePaths(vector<Path> possiblePaths);

	/*** Getter ***/
	vector<Path> getPossiblePaths(); 

	/*** Additional Methods ***/

	/*
	This method adds a path to the possiblePaths vector.
	@param	currentPath						Successful path that led to the destination city
	@return void					
	*/

	void add_PathtoPossiblePaths(Path currentPath);

	/*
	This method finds all possible connections (paths) between start city and destination (end) city by means of backtracking.
	@param	currentCity						The current city along the path whose unvisited neighbours are to be found
	        end								Destination city (is always the same). Is obtained from Way_Calculator
	@return possiblePaths					Vector of path objects that lead from start to end.
	*/

	vector<Path> everyWay(City* currentCity, City* end);

};

