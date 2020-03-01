#ifndef PREPROCESSOR_BEST_WAY_H
#define	PREPROCESSOR_BEST_WAY_H

#include "Way_Calculator.h"

class Preprocessor_BestWay :
	protected Way_Calculator
{
protected:
	unsigned int costAsReference=-1;		// Maximalen Int-Wert erzeugen

public:
	// Default Constructor
	Preprocessor_BestWay();

	/*----------------------------------------------------------------------
							Methods
	-----------------------------------------------------------------------*/
	

	/*
	This method finds a reference cost for the following Dijkstra algorithm, so that the search of the best way is biased and wont't run into a dead end for too long.
	@param	start					starting point
			end						end point
	@return distanceAsReference		reference cost for the Dijkstra algorithm
	*/
	void find_costAsReference(int start, int end);

	// Getter
	unsigned int get_costAsReference();
};
#endif
