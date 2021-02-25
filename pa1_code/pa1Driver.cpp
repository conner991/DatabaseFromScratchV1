/* -----------------------------------------------------------------------------
FILE NAME:         
DESCRIPTION:       
USAGE:             
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Conner Fissell     02-21-2021         1.0  Original version
----------------------------------------------------------------------------- */
#include "pa1.h"
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



#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// #pragma warning(disable : 4996)

// Prototypes
// void RNG(int treeNums[], int range);
// void visit(int &num);
bool inputParser(std::string inputLine, bool &running);

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char* argv[])
{

     std::fstream file;


     bool running = true; 
     std::string inputLine;

     // Enter SQL Mode
     while (running) {
          std::cout << "--> ";
          std::getline(std::cin, inputLine);
          running = inputParser(inputLine, running);
     }












     // Create a directory
     //const char* testString = "test";
     // if (mkdir(testString, 0777) == -1){
     //      std::cout << "Error creating Directory\n";
     // }
     // else {
     //      std::cout << "directory created\n";
     // }
          
     

     // Remove an empty directory
     //int removed = rmdir("test");




     // Remove a directory with files in it
     // std::string s(testString);
     // std::string x = "rm -r " + s;
     // system(x.c_str());

     















          // string temp;
          //   if(INTERACTIVE == -1)
          //   {//if not in interactive mode but INTERACTIVE == -1, it awits for the user to hit enter between each command, but otherwise goes through the file as normal
          //       cout << "Waiting...";
          //       cin.ignore();
          //   }

          //   //To get the proper file i want to readline until the last chunk is a ;
          //   //Ignore line if the first 2 characters are --
            
          //   if(sql.is_open())
          //   {

          //       while(temp[temp.length()-1] != ';' && lowerCase(temp)!=".exit"){
          //           sql>>temp;
          //           if(temp.substr(0,2) != "--"){   //to make sure we dont get comments
          //               input += temp + ' ';
          //           }
          //           else getline(sql, temp);//and if we do get comments we can get rid of it by going to the next line
          //       }
          //       if(INTERACTIVE == -1) cout << input << endl;//and if in -1 mode, it reads off the command given
          //   }























}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
bool inputParser(std::string input, bool &running)
{
     // on exit, add edge cases here
     if (input == ".exit"){
          running = false;
          return running;
     }

     std::vector<std::string> inputChunks;
     std::string string1, string2, string3;
     int spacePosition, numOfSpaces = 0, numOfWords; 

     // Find the number of spaces in the input
     for(int i = 0; i < input.length(); i++) {
          if (input.at(i) == ' ')
               ++numOfSpaces;
     }

     // If there are multiple words in the input
     if (!numOfSpaces == 0) {
          
          // Finds the first space in a string and gives us its position number
          spacePosition = input.find(' ', 1);
          std::cout << spacePosition << std::endl;

          // Creates a string out of the first part of the input
          string1.assign(input, 0, spacePosition);
          std::cout << string1 << std::endl;
     }

     // There is only one word in the input
     else {
          std::cout << numOfSpaces << std::endl;
     }

     
      



     






     return running;

}
