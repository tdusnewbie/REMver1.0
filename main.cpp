////////////// Finish all at Tuesday, October 18th, 2017 23:59 ////////////////
////////////// Finish Fix bugs and run program at Wednesday, October 19th, 2017 14:50 ////////////////

#include "auto.h"
#include "chat.h"
#include "hello.h"

int main()
{
	int orginalSleep = takeTime(); // take orginal time at start program (ater running computer)
	int orginalSet = takeTime(); //take original time for set time funtion
	int orginalShutdown = takeTime(); // take orginal time for sleep early function
	string commandUser;
	int numAdviceShutdown =0;
	int numOfAdviceSuspend = 1;
	bool executeHello;
	cin.ignore();
	while(1)
	{
		executeHello = false;
		int hours = takeHours();
		givePlanAdvice(orginalSet);
		sleepEarly(hours,orginalShutdown,numAdviceShutdown);
		autoGiveAdvice(hours);
		cout << USER;
		getline(std::cin, commandUser);
		sayHello(commandUser,hours,executeHello);
		if(executeHello == false)
		{
			string answer;
			int rowstoAnswer;
			rowstoAnswer = recognizeInPut(commandUser);
			if(rowstoAnswer != 0)
			{
				answer = randomOutPut(rowstoAnswer);
				cout << REM_SYS << answer << endl;
			}
		}
	}
	return 0;
}
