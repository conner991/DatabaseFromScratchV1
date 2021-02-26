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
bool inputParser(std::string inputLine, std::vector<std::string> &wordVector, bool &running);
void wordDecider(std::vector<std::string> &words);
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
     std::vector<std::string> wordVector;

     // Enter SQL Mode
     while (running) {
          std::cout << "--> ";
          std::getline(std::cin, inputLine);
          running = inputParser(inputLine, wordVector, running);

          // If .exit was not entered, move forward in program
          if (!wordVector.size() == 0) {
               wordDecider(wordVector);
          }
          
          // clear vector of input strings after each SQL command
          wordVector.clear();
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
bool inputParser(std::string input, std::vector<std::string> &wordVector, bool &running)
{    
     std::string word, string2, string3;
     int spacePosition, numOfSpaces = 0, numOfWords; 

     

     // Find the number of spaces in the input
     for(int i = 0; i < input.length(); i++) {
          if (input.at(i) == ' ')
               ++numOfSpaces;
     }

     // If there are multiple words in the input
     if (!numOfSpaces == 0) {
          
          numOfWords = numOfSpaces + 1;
          
          for (int i = 0; i < numOfWords; i++) {
               
               // Finds the first space in a string and gives us its position number
               spacePosition = input.find(' ', 1);

               // Creates a string out of the first part of the input
               word.assign(input, 0, spacePosition);
               
               // Adds word to the string vector
               wordVector.push_back(word);

               // Need to modify input string to capture the rest of the input words
               input.erase(0, spacePosition + 1);

          } 
          
     }

     // There is only one word in the input and it should be .EXIT
     else {

          // Add single string to vector
          wordVector.push_back(input);

          // Make any letters in it lowercase
          std::transform(wordVector[0].begin(), wordVector[0].end(), wordVector[0].begin(), ::tolower);

          if (wordVector[0] == ".exit") {
               wordVector.clear();
               running = false;
               return running;
          }

          else {
               wordVector.clear();
               std::cout << "Unknow Entry\n";
          }

          
     }


     return running;

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void wordDecider(std::vector<std::string> &words) 
{
     // Make all letters in vector of string words lowercase
     for (int i = 0; i < words.size(); i++){
          std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
          //std::cout << words[i] << std::endl;
     }

     // Check first word in vector to see if it is one of the beginning SQL keywords
     if (words[0] == "create" || words[0] == "drop" || words[0] == "use" || words[0] == "select" || words[0] == "alter") {
          
          if (words[0] == "create"){
               
               // then we're either gonna create a database or a table (one of those SQL keywords will follow)
               if (words[1] == "database") {
                    std::cout << "Creating database\n";
               }

               else if (words[1] == "table") {
                    std::cout << "Creating table\n";
               }

               else {
                    std::cout << "Unknown Entry\n";
               }
          }
     }

     else {
          std::cout << "Unknown Entry\n";
     }
     

}