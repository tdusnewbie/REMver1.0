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

unsigned int takeTime();
bool setDelay(unsigned int orginal, unsigned int timeDelay);
unsigned int convertTimeToSecond(unsigned int days, unsigned int months, unsigned int years, unsigned int hours, unsigned int minutes);
void sleepEarly(unsigned int &hours,unsigned int &orginal, int &numAdvice);
void setTimeForPlan(string command);
void givePlanAdvice(int &orginalSet);
void autoSleep(unsigned int &orginalBegin);
void autoGiveAdvice(unsigned int &hours);
