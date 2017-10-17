#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>


// Create macro
#define REM_SYS "[REM 1.0] : "
#define USER "[Boss] : "

using namespace std;

bool checkTypeSentences(string command);
bool checkTimeWithCommand(string command, int hours);
void sayHello(string &command, int &hours, bool &executeHello);