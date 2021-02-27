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



#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// #pragma warning(disable : 4996)

// Prototypes
bool inputParser(std::string inputLine, std::vector<std::string> &wordVector, bool &running);
void wordDecider(std::vector<std::string> &wordVector, std::vector<std::string> &databaseVector, int &dbCount);
void createDB(std::string dbName, std::vector<std::string> &databases, int &dbCount);
void deleteDB(std::string name, std::vector<std::string> &databases, int &dbCount);
void createTable();
void deleteTable();
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
     int dbCount = 0;
     std::string inputLine;
     std::vector<std::string> wordVector, databaseVector;

     // Enter SQL Mode
     while (running) {
          std::cout << "--> ";
          std::getline(std::cin, inputLine);
          running = inputParser(inputLine, wordVector, running);

          // If .exit was not entered, move forward in program
          if (wordVector.size() != 0) {
               wordDecider(wordVector, databaseVector, dbCount);
          }
          
          // clear vector of input strings after each SQL command
          wordVector.clear();
     }
          
     

     // Remove an empty directory
     //int removed = rmdir("test");




     

     


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


     // Make any letters in input string lowercase
     std::transform(input.begin(), input.end(), input.begin(), ::tolower);
     
     // Check to make sure there is a semicolon at the end of the statement
     if (input.back() == ';' || input == ".exit") {
          
          // Find the number of spaces in the input
          for(int i = 0; i < input.length(); i++) {
               if (input.at(i) == ' ')
               ++numOfSpaces;
          }
     
     
          // If there are multiple words in the input
          if (numOfSpaces != 0) {
          
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



          
     }

     else {
          std::cout << "Input statement must end with a semicolon.\n";
     }
          

     


     return running;

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void wordDecider(std::vector<std::string> &wordVector, std::vector<std::string> &databaseVector, int &dbCount) 
{    
     int oldSize, newSize;
     char frontOfString;
     



     // Make all letters in vector of string words lowercase
     for (int i = 0; i < wordVector.size(); i++){
          std::transform(wordVector[i].begin(), wordVector[i].end(), wordVector[i].begin(), ::tolower);
     }



     // Check first word in vector to see if it is one of the beginning SQL keywords
     if (wordVector[0] == "create" || wordVector[0] == "drop" || wordVector[0] == "use" || wordVector[0] == "select" || wordVector[0] == "alter") {
          
          if (wordVector[0] == "create") {
               
               // then we're either gonna create a DATABASE or a TABLE (one of those SQL keywords will follow)
               
               // CREATE DATABASE
               if (wordVector[1] == "database") {

                    // Theres going to be a ";" at the end of our database name that we need to get rid of
                    oldSize = wordVector[2].size();
                    newSize = oldSize - 1;
                    wordVector[2].resize(newSize);
                    
                    // Call createDB function to create DB
                    std::string dbName1 = wordVector[2];
                    createDB(dbName1, databaseVector, dbCount);

               }

               // CREATE TABLE
               else if (wordVector[1] == "table") {
                    
                    // Create tbl_x out of wordVector[2]

                    std::cout << "Table " << wordVector[2] << " created.\n";

                    // Check if there is a "(" following tbl_x
                    frontOfString = wordVector[3].front();
                    if (frontOfString == '('){
                         std::cout << "reading a parenthetical statement\n";
                         
                         // now to work on the attributes = ax within parenthesis
                    }

                    else {
                         std::cout << "parenthetical expression must follow tbl_x\n";
                    }

                    
               }

               else {
                    std::cout << "DATABASE or TABLE must follow CREATE\n";
               }
          }



          if (wordVector[0] == "drop"){
               
               // Same as "CREATE" except we're either gonna drop a created database or a table

               // DROP DATABASE
               if (wordVector[1] == "database") {
                    
                    // Theres going to be a ";" at the end of our database name that we need to get rid of
                    oldSize = wordVector[2].size();
                    newSize = oldSize - 1;
                    wordVector[2].resize(newSize);

                    // Call deleteDB function to delete wordVector[2] database name
                    std::string dbName2 = wordVector[2];
                    deleteDB(dbName2, databaseVector, dbCount);
                    
               }

               // DROP TABLE
               else if (wordVector[1] == "table") {
                    
                    // Theres going to be a ";" at the end of our table name that we need to get rid of
                    oldSize = wordVector[2].size();
                    newSize = oldSize - 1;
                    wordVector[2].resize(newSize);
                    
                    // Now delete wordVector[2] table

                    std::cout << "Table " << wordVector[2] << " deleted.\n";
               }

               else {
                    std::cout << "DATABASE or TABLE must follow DROP.\n";
               }
          }



          if (wordVector[0] == "use"){
     
               // Next word after "USE" is a database name with ;

               // Theres going to be a ";" at the end of our database name that we need to get rid of
               oldSize = wordVector[1].size();
               newSize = oldSize - 1;
               wordVector[1].resize(newSize);
               std::cout << "Using database " << wordVector[1] << ".\n";

               // USE our database wordVector[1] and check to see if we are already using it if this happens again
               
          }



          if (wordVector[0] == "select") {
 
               // SELECT is always going to be followed by an action performed on a table
               
               // Next word after SELECT should be an *
               if (wordVector[1] == "*") {

                    // Here we're going to SELECT all of the attributes from our table


                    // Using FROM after *
                    if (wordVector[2] == "from") {
                         std::cout << "selecting ALL attributes FROM created tbl_x\n";

                         // Display all of the attributes (columns) of tbl_x (wordVector[3])

                         // Theres going to be a ";" at the end of our table name that we need to get rid of
                         oldSize = wordVector[3].size();
                         newSize = oldSize - 1;
                         wordVector[3].resize(newSize);
                         std::cout << "Display attributes (columns) of " << wordVector[3] << " here\n";
                    }

                    else {
                         std::cout << "FROM must follow *\n";
                    }
               }
          
               else {
                    std::cout << wordVector[1] << " doesn't work with SELECT\n";
               }
               
          }



          if (wordVector[0] == "alter"){
               
               // Next word after "alter" is only ever going to be a SQL table keyword and that must be a created table
               if (wordVector[1] == "table") {

                    // ALTER is only ever going to work with a created table
                    
                    
                    if (wordVector[3] == "add") {
                         
                         // attribute name (wordVector[4]) and datatype (wordVector[5] with a semicolon) are entered here
                         // add attribute to tbl_x here

                         std::cout << "Table " << wordVector[2] << " modified.\n";
                    }

                    
               }

               else {
                    std::cout << "Must be TABLE keyword\n";
               }
               
          }
     }

     else {
          std::cout << "Unknown Entry\n";
     }
     

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void createDB(std::string name, std::vector<std::string> &databaseVector, int &dbCount) 
{    
     bool inVector = false;

     // If there are more than 1 database entrys in our vector
     if (dbCount > 1) {
          
          for (auto i = databaseVector.begin(); i != databaseVector.end(); i++) {

               if (*i == name) {
                    std::cout << "!Failed to create database " << name << " because it already exists.\n";
                    inVector = true;
               }

          }

          if (!inVector) { 
               // Now create a database with name by creating a directory in our project
               const char* dbName = name.c_str();
                    
               if (mkdir(dbName, 0777) == -1) {
                    std::cout << "Error creating Database\n";
               }

               else {

                    // Add name of database to vector
                    databaseVector.push_back(dbName);
                    std::cout << "Database " << dbName << " created.\n";
               }

               dbCount++;
          }

     }

     else if (dbCount == 1) {    

          if (databaseVector.front() == name) {
               std::cout << "!Failed to create database " << name << " because it already exists.\n";
          }

          else {

               // Now create a database with name by creating a directory in our project
               const char* dbName = name.c_str();
                    
               if (mkdir(dbName, 0777) == -1) {
                    std::cout << "Error creating Database\n";
               }

               else {

                    // Add name of database to vector
                    databaseVector.push_back(dbName);
                    std::cout << "Database " << dbName << " created.\n";
               }

               dbCount++;
          }
     }

     // Our database vector is empty 
     else {
          // Now create a database with name by creating a directory in our project
          const char* dbName = name.c_str();
                    
          if (mkdir(dbName, 0777) == -1) {
               std::cout << "Error creating Database\n";
          }

          else {

               // Add name of database to vector
               databaseVector.push_back(dbName);
               std::cout << "Database " << dbName << " created.\n";
          }

          dbCount++;
     }

     
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void deleteDB(std::string name, std::vector<std::string> &databaseVector, int &dbCount) 
{         
     std::string tempName1, tempName2;

     // If we have more than 1 database string in our vector
     if (dbCount > 1) {
          
          // Delete database, removes the corresponding directory string from the vector
          // by searching for it   
          for (auto i = databaseVector.begin(); i != databaseVector.end(); i++) {
          
               if (*i == name) {
                    
                    tempName1 = *i;
                    databaseVector.erase(i);

                    // Delete database directory from project directory
                    std::string removalString = "rm -r " + tempName1;
                    system(removalString.c_str());
                    std::cout << "Database " << tempName1 << " deleted.\n";

                    dbCount--;      

                    break;              
               }
               
          }
     }

     
     // if dbCount is equal to 1
     else if (dbCount == 1) {
          
          if (databaseVector.front() == name) {
               
               // Delete database directory from project directory
               databaseVector.clear();
               std::string removalString = "rm -r " + name;
               system(removalString.c_str());
               std::cout << "Database " << name << " deleted.\n";

               dbCount--;
          }

          else {
               std::cout << "!Failed to delete database " << name << " because it does not exist.\n";
          }
          
     }

     // else we are trying to delete an entry from an empty vector.  
     else {
          std::cout << "!Failed to delete database " << name << " because it does not exist.\n";
     }
     
         
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void createTable() 
{
     std::vector<Attribute> attributes;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void deleteTable() 
{

}