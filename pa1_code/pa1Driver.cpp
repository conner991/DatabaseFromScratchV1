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

#include <stdio.h>


#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// #pragma warning(disable : 4996)

// Prototypes
void RNG(int treeNums[], int range);
void visit(int &num);
/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char* argv[])
{

     std::fstream file;






     // Create a directory
     const char* testString = "test";
     if (mkdir(testString, 0777) == -1){
          std::cout << "Error creating Directory\n";
     }
     else {
          std::cout << "directory created\n";
     }
          
     

     // Remove an empty directory?























          // string temp;
          //   if(INTERACTIVE == -1){//if not in interactive mode but INTERACTIVE == -1, it awits for the user to hit enter between each command, but otherwise goes through the file as normal
          //       cout << "Waiting...";
          //       cin.ignore();
          //   }
          //   //To get the proper file i want to readline until the last chunk is a ;
          //   //Ignore line if the first 2 characters are --
            
          //   if(sql.is_open()){

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

// /* -----------------------------------------------------------------------------
// FUNCTION:          
// DESCRIPTION:       
// RETURNS:           
// NOTES:             
// ------------------------------------------------------------------------------- */
// void RNG(int treeNums[], int range)
// {

//     //RNG
//     unsigned seed = time(0);
//     srand(seed);

//     for (int i = 0; i < range; i++)
//     {
//         treeNums[i] = (rand() % range) + 1;
//     }
// }

// /* -----------------------------------------------------------------------------
// FUNCTION:          
// DESCRIPTION:       
// RETURNS:           
// NOTES:             
// ------------------------------------------------------------------------------- */
// void visit(int &num)
// {
//     std::cout << num << std::endl;
// }

// /* -----------------------------------------------------------------------------
// FUNCTION:          
// DESCRIPTION:       
// RETURNS:           
// NOTES:             
// ------------------------------------------------------------------------------- */

// /* -----------------------------------------------------------------------------
// FUNCTION:          
// DESCRIPTION:       
// RETURNS:           
// NOTES:             
// ------------------------------------------------------------------------------- */