#ifndef _UTIL_
#define _UTIL_

#include <string>
#include <sstream>
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
		unsigned int hrs = minutes / 60;							// holds the amount of hrs
		unsigned int min = minutes - (hrs * 60);					// by substracting hrs*60 (min) the remaining amount of minutes is obtained

		string hours = to_string(hrs);
		string mins = to_string(min);

		if (hrs < 10) {
			hours = "0" + hours;									// puts a "0" in front of one-digit-amount of hours  
		}

		if (min < 10) {
			mins = "0" + mins;									// puts a "0" in front of one-digit-amount of hours  
		}
			
		string hrsRepresentation = hours + ":" + mins;

		return hrsRepresentation;
	}
};
#endif
