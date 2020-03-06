#include <iostream>
#include <fstream>
#include <string>

#include "messages.hpp"

using namespace std;


// initialize language for messages
unordered_map<string, string> MSG = MSG_EN;

// Run a source file
void runFile(string source_file) {
  ifstream source(source_file);

  string line;
  if (source.is_open())  {
    while ( getline(source, line) ) {
      cout << line << endl;
    }
    source.close();
  }

  else cerr << MSG["ERROR::CANNOT_OPEN_SOURCEFILE"] << source_file << endl; 
}


// run interactively
void runPrompt() {
  cout << MSG["CMDLINE_INTRO"] << endl;    
  cout << MSG["PROMPT"];
}


// ...
int main(int argc, char *argv[])
{
  if (argc > 2) {                                   
    cerr << MSG["ERROR::USAGE_SCRIPT"] << endl;            
    exit(1);                                 
  } else if (argc == 2) {                           
    runFile(argv[1]);                                      
  } else {                                                 
    runPrompt();                                           
  }                              
}


