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


class Table {
     private:
          std::string tableName;
          int numOfAttributes;
          std::vector<Attribute> attributes;

     public:

          Table();
          Table(std::string name) {
               tableName = name;
          }

          void displayTableName() {
               std::cout << "Table name is: " << tableName << "\n";
          }

          void insertAttribute(Attribute a) {
               attributes.push_back(a);
          }

          void displayAttributes(Table table) {

               for (int i = 0; i < attributes.size(); i++) {
                    
                    table.attributes[i].displayAttribute();
               }
               
          }

          // friend std::ostream& operator << (std::ostream &stream, Table &table) {
          

          //      for (int i = 0; i < table.attributes.size(); i++) {
                    
          //           stream << table.attributes[i].displayAttribute();
          //      }
          // }

          

};
























#endif
