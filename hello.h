#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <hello.h>

// Create macro
#define USER "[Boss ] : "
#define REM_SYS "[REM 1.0] : "

using namespace std;

bool checkTypeSentences(string command);
bool checkTimeWithCommand(string command, unsigned int hours);
void sayHello(string &command, unsigned int &hours);