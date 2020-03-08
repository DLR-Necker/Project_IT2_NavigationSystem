#ifndef _UTIL_
#define _UTIL_

#include <string>
using namespace::std;


class utility
{
public:

	/*----------------------------------------------------------------------
								Methods
	-----------------------------------------------------------------------*/
	/*
	This method converts an unsigned int number of minutes into an hours:min representation 
	@param	minutes			to be converted into hrs::min
	@return string
	*/
	string convert_minutesToHours(unsigned int minutes) {
		unsigned int hrs = minutes / 60;			// holds the amount of hrs
		unsigned int min = minutes - (hrs * 60);	// by substracting hrs*60 (min) the remaining amount of minutes is obtained

		string hrsRepresentation = hrs + ":" + min;

		return hrsRepresentation;
	}
};
#endif
