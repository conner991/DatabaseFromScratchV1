/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:        
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     **-**-2020         1.0  Original version
----------------------------------------------------------------------------- */
#ifndef __pa1_H__
#define __pa1_H__

#include "pa1Interface.h"



class Attribute : public Table {
     private: 
          std::string attributeName, attributeType;

     public:
          Attribute();
          Attribute(std::string name, std::string type) {
               attributeName = name;
               attributeType = type;
          }

          void displayAttribute() {
               std::cout << attributeName << " " << attributeType;
          }
          
          

};











#include "pa1.cpp"

#endif