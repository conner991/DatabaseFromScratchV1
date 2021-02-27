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
#ifndef __pa1Interface_H__
#define __pa1Interface_H__

#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

#include <stdio.h>
#include <unistd.h>


class Attribute {
     private:
          std::string name, type;
          std::vector<Attribute> attributes;

     public:
          Attribute(std::string title, std::string data) {
               name = title;
               type = data;

          }

          void displayAttribute() {
               std::cout << name << " " << type;
          }

};
























#endif
