/**************************************************************************/
/*!
  @file   Averager.cpp
  Author: Chris Veigl (Asterics Foundation)
  License: GPL (see license.txt)

  This is a library provides a simple running average value for integer values
 

  @section author Author
  Chris Veigl (AsTeRICS Foundation)
  @section license License
  GPL (see license.txt)
*/
/**************************************************************************/

#include <Arduino.h>
#include "Averager.h"


/**************************************************************************/
/*!
    @brief  creates a new Averager object with given length, allocates buffer
	@param avglen: the buffer length
*/
/**************************************************************************/
Averager::Averager (int avglen) {
	buf = (int *) malloc (sizeof(int)*avglen);
	len = avglen;
	for (int i=0; i<avglen; i++) buf[i]=0;   // clear buffer
	sum = 0;
	pos = 0;
}


/**************************************************************************/
/*!
    @brief  processes the next raw data value, must be called periodically
    @param value Raw data value.
    @return running average of the last <len> values.
*/
/**************************************************************************/
int Averager::process (int value) {
  if (len<=1) return (value);
  buf[pos] = value;
  sum += value;
  pos = (pos+1) % len;
  sum -= buf[pos];      //remove oldest value from running sum!
  return (sum/(len-1));
}



/**************************************************************************/
/*!
    @brief  destructs an existing Averager object, frees buffer memory
*/
/**************************************************************************/

Averager::~Averager () {
  if (buf != NULL) free (buf);
}





