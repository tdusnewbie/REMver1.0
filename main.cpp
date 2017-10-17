#include "auto.h"
#include "chat.h"
#include "hello.h"

int main()
{
	int orginalSleep = takeTime(); // take orginal time at start program (ater running computer)
	int orginalSet = takeTime(); //take original time for set time funtion
	int orginalShutdown = takeTime(); // take orginal time for sleep early function
	string commandUser;
	int numAdvice =0;
	cin.ignore();
	bool executeHello;
	while(1)
	{
		executeHello = false;
		int hours = takeHours();
		givePlanAdvice(orginalSet);
		sleepEarly(hours,orginalShutdown,numAdvice);
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