#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#define REM_SYS "[REM 1.0] : "
#define USER "[Boss] : "

using namespace std;

int takeTime();
int takeHours();
bool setDelay(int orginal, int timeDelay);
int convertTimeToSecond(int days, int months, int years, int hours, int minutes);
void sleepEarly(int &hours,int &orginal, int &numAdvice);
void setTimeForPlan(string command);
void givePlanAdvice(int &orginalSet);
void autoSleep(int &orginalBegin, int &hours, int &numofAdvice);
void autoGiveAdvice(int &hours);
