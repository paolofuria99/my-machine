#ifndef MYMACHINE_H
#define MYMACHINE_H

#include <string.h>
#include <cmath>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>


#include <iostream>

//#include "EB_Device.h"
#include "lever.h"
#include "EB_Device.h"


using namespace std;
/** Function that create a string svg containing the image of the Machine
 *  
 *  @param ebshaft Structure/Device like EbDevice
 *  @param myshaft stucture containg the data of the shaft
 *  @param mysquares stucture containg the data of the squares
 */
string to_svg_Machine(EbDevice* eb_device, Pol_shaft* myshaft, Pol_squares * mysquares);


#endif