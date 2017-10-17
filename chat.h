#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


// Create macro
#define REM_SYS "[REM 1.0] : "
#define USER "[Boss] : "


using namespace std;

void saveFileInPut(ofstream &file, string &command);
void saveFileOutPut(ofstream &file);
void learnNewConversation(string &command);
int recognizeInPut(string command);
string takeStringOfRowInFile(ifstream &file, int rows);
string randomOutPut (int rowsInPut);