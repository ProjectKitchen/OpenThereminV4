/**************************************************************************/
/**
  @file   Averager.h
  Author: Chris Veigl (Asterics Foundation)
  License: GPL (see license.txt)

  This is a library provides a simple running average value for integer values
  
*/
/**************************************************************************/


/**************************************************************************/
/*!
    @brief  Averager class
*/
/**************************************************************************/

class Averager {
public:
  Averager(int avglen=10);
  ~Averager();
  int   process(int value);


private:
  int * buf;
  int len;
  int pos;
  long sum;  
};
