/////////////// Finish all at Monday,October 16th, 2017 15h30p /////////////////////
/////////////// Fixing All bugs at .......... ////////////////////

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

/*Support Functions */

// Taking time Function (by second and from 0h0m0m0year to now)

unsigned int takeTime()
{
	time_t timer;
	time(&timer);
	return timer;
}


// Calculating and Setting Delay time Fuction

bool setDelay(unsigned int orginal, unsigned int timeDelay)
{
	unsigned int current = takeTime();
	if(current - orginal >= timeDelay) // If condition is right
	{
		orginal = current;// orginal time will be overloadding by current time
		return true; // then ... function will return value TRUE
	}
	else // if condition is wrong 
		return false; // function will reuturn value FALSE
}

// Convert from (dd/mm/yyyy, hh:mm:ss) to second (begin at 0:0:00 0/0/1900)
// This function is created to save time simplier than save all string dd/mm/yyyy, hh:mm
// Howevver, this will make developer feel so hard when connect to file and get data in file 
unsigned int convertTimeToSecond(unsigned int days, unsigned int months, unsigned int years, unsigned int hours, unsigned int minutes)
{
	time_t timer;
	struct tm *timeSet;
	time(&timer);
	// Take time at current stage
	timeSet = localtime(&timer);
	// Overload all valuable for struct tm
	timeSet->tm_mday = days -1;
	timeSet->tm_mon = months -1;
	timeSet->tm_year = years -1900;
	timeSet->tm_hour = hours -1;
	timeSet->tm_min = minutes;
	// Covert time to seconds
	unsigned int convertTime = mktime(timeSet);
	// After that .... function will return second it have coverted
	return convertTime;
}
/*Auto Functions*/

///////// Create some function can protect own health ///////////
/////////////////////////////////////////////////////////////////

// Sleep Early Function(Auto Shutdown system to make user go to sleep early)

void sleepEarly(unsigned int &hours,unsigned int &orginal, int &numAdvice)
{
	if(hours >=0 && hours <= 3) // if from 0h to 3h, you still working
	{
		bool check = setDelay(orginal,300); /// check time to give advice again
		{
			cout << REM_SYS << "Hmmm !!! "<< endl;
			sleep(2);
			vector <string> adviceSleepFirst;
			vector <string> adviceSleepSecond;
			string temp;
			ifstream getFile ("~/REMver1.0/REMfile/sleepEarly"); // connect and read file sleepEearly.txt
			if(getFile.is_open())// If file has existed
			{
				while(getline(getFile,temp)) // copy content of first time in file to vector array adviceSleepFirst
				{
					if(temp != "first")
					{
						adviceSleepFirst.push_back(temp);
					}
					if(temp == "second")
						break;
				}
				while(getline(getFile,temp)) // Copy content of second time in file to vector array adviceSleepSecond
				{
					adviceSleepSecond.push_back(temp);
				}
			}
			getFile.close();
			// Take an answer randomly at first time
			srand(time(NULL));
			int ran = rand() % adviceSleepFirst.size();
			cout << REM_SYS << adviceSleepFirst.at(ran) << endl;
			cout << USER ;
			string answer;
			getline(std::cin, answer);
			if(answer.find("yes") != std::string::npos || answer.find("ok") != std::string::npos) // If user agree with system's suggestion
			{
				cout << REM_SYS << "Love you !!! Good night and have a best wish !! ^^" << endl;
				system("shutdown -h now");
			}
			else if (numAdvice <= 2) // if user disagree with this suggestion
			{
				// case 1
				// If system's suggestion number is lower than 2 or same as 2, user can use computer normally and after 300s (5p) system will give advice again
				numAdvice ++;
				ran = rand() % adviceSleepSecond.size();
				cout << REM_SYS << adviceSleepSecond.at(ran);
			}
			else
			{
				//case 2
				// If system's suggestion number is higher than 2, system will auto shutdown laptop and won't allow user to turn on computer again !!!
				cout << REM_SYS << "Haizzz " << endl;
				sleep (2);
				cout << REM_SYS << "I have adviced you two time .... However, you don't care them .... So .. I think I will use 'violent measures' !!!" << endl;
				cout << REM_SYS << " Good night My Boss !!!! " << endl;
				sleep (1);
				system("shutdown -h now");
			}
		}
	}
}

// Set time For Plan Function (Please provide clearly hour number, minute number to system)

void setTimeForPlan(string command)
{
	// Recognize words in command user provide ... If Those words exist in user's command
	if(command.find("set time ") != std::string::npos || command.find("call me at ") != std::string::npos || command.find("advice ") != std::string::npos)
	{ 
		// Ask user again to sure that him/her want to set time or not
		cout << REM_SYS << "You wanna set time for your plan , Right ????? (Y/n) : " << endl;
		char choose;
		cin >> choose;
		// If user say Y(Yes), it mean system will begin run set time function below
		if(choose != 'N' && choose != 'n')
		{
			cout << REM_SYS << "OK !!! " << endl;
			sleep(2);
			string setHours,setDays,setMessages;
			//Allow user can input again if he/she input wrong
			do
			{
				cout << REM_SYS << "PLease enter the day your plan is going on (dd/mm/yyyy) : " << endl;
				cout << USER ;
				getline(std::cin,setDays);
				setDays+="/";
				cout << REM_SYS << "Well !!!! ...... " << endl;
				sleep(1);
				cout << REM_SYS << "Ok !!! So Can you tell me What time your plan is going on (hh:mm => 24h Type) : " << endl;
				cout << USER ;
				getline(std::cin, setHours);
				setHours+=":";
				cout << REM_SYS << "Hmmm!!!! " << endl;
				sleep(1);
				cout << REM_SYS << "So ... How about some message for that plan ??? " << endl;
				cout << USER;
				getline(std::cin,setMessages);
				setMessages += "_";
				setMessages += setHours;
				setMessages += "_";
				cout << REM_SYS << ".........." << endl;
				sleep(1);
				cout << "So ..... " << endl;
				sleep(1);
				cout << REM_SYS << "Your plan will go on at " << setDays << " " << setHours << " with the message is : "<< setMessages <<", Right ???? (Y/n) : " << endl;
				cout << USER ;
				cin >> choose;
				//Check one more time to sure that all above is what user want
				if(choose != 'n' || choose != 'N')
				{
					// Ater that ... recognize which user has input and classify hour, minute, day, month, year
					size_t flag = 0;
					size_t pos = setDays.find_first_of("/");
					vector <int> dates;
					while(pos != std::string::npos) // classify day, month, year
					{
						dates.push_back(stoi(setDays.substr(flag,pos-flag)));
						flag = pos +1;
						pos = setDays.find_first_of("/",pos + 1);
					}
					flag = 0;
					pos = setHours.find_first_of(":");
					while(pos != std::string::npos) // classify hour, minute
					{
						dates.push_back(stoi(setHours.substr(flag,pos-flag)));
						flag = pos +1;
						pos = setHours.find_first_of(":",pos + 1);

					}
					// after classifying, covert all into seconds
					int covertSecond = convertTimeToSecond(dates.at(0),dates.at(1),dates.at(2),dates.at(3),dates.at(4));
					string convertSecondString;
					convertSecondString += covertSecond;
					cout << REM_SYS << "Well ..... "<< endl;
					sleep(1);
					vector <string> finishedSetPlan;
					finishedSetPlan.push_back("Fine !! I will call you at that time !!!");
					finishedSetPlan.push_back("OK ... Your plan is saved in My Memories !!!! Don't worry about this !!! ^^ ");
					srand(time(NULL));
					int ran = rand() % finishedSetPlan.size();
					cout << REM_SYS << finishedSetPlan.at(ran) << endl;
					// save all plan user has set in file plans.txt
					ofstream putFile ("~/REMver1.0/REMfile/plans.txt",ios::app);
					putFile << covertSecond << endl;
					putFile << setMessages << endl;
					// close file after finishing set time
					putFile.close();
				}	
			} while(choose == 'n'||choose == 'N');
		}
		else // If user say N(no) .... it means they don't wanna set time .... so system must pass this function
		{
			cout << REM_SYS << "Allright !!! Maybe I was wrong !!!! Sorry !! ^^ " << endl;
			sleep(2);
		}
	}
}

// Auto give advices or suggestions for user if they have set time for their plan with system

void givePlanAdvice(int &orginalSet)
{
	// Open file plans.txt
	ifstream getFile ("~/REMver1.0/REMfile/plans.txt");
	if(getFile.is_open())
	{
		string temp, message, timePlan;
		double checkDelayPlan;
		int rows = 1;
		bool check = false;
		while(getline(getFile,temp)) // Read file
		{
			if(rows % 2 != 0) // At odd rows
			{
				// check distance from orginalSet to temp is how far
				if(difftime(orginalSet,stoi(temp)) <= 24*3600 && difftime(orginalSet,stoi(temp)) >= 0)
				{
					// If this distance is lower than 1 day or same as 1 day ... will give advice for this time as below
					check == true;
				}
			}
			if(rows % 2 == 0 && check == true) // At even rows
			{
				// get Message user has saved in file plans.txt
				int numExc = 0;
				size_t flag = 0;
				size_t pos = temp.find_first_of("_");
				while(pos != std::string::npos ) // Because I want this program is more flexible, I have added time string user input above at the end of this message
				{
					// system will divide string content message into two part .... 
					if(numExc <1)
					{
						message = temp.substr(flag,pos-flag); // One part will content message
						numExc++;
					}
					else
						timePlan = temp.substr(flag,pos-flag); // Another one will content time string
					flag = pos +1;
					pos = temp.find_first_of("_",pos + 1);

				}
				check = false;
				break;
			}
			rows++ ;
		}
		// After classifying... system will give advice like below 
		if(timePlan != "" && message != "")
		{
			cout << REM_SYS <<"Hmmm !!! " << endl;
			sleep(2);
			cout << REM_SYS << "My boss !!! At " << timePlan << " you have a plan with a message : " << endl;
			cout << "[ " << message << " ]" << endl;
			cout << REM_SYS << "Please don't forget your plan !!! ^^ " << endl;

		}
	}
}

// Auto sleep computer function (If you work over 2 hours ... System will auto sleep to give you time to relax)

void autoSleep(unsigned int &orginalBegin)
{
	/// This problem must be solved by multiProcessing 
	/// May be at that time i think that we need to divide our program to two or three process
	/// One Part will manage time and auto function and another one will mange chat.cpp hello.cpp
	/// May be we will have or must be create some process managing picture and some animated effect
	/// they will help us easily manage our program better and better 
}

// Auto give some basic advices (time to come back home, or time to have lunch, etc)

void autoGiveAdvice(unsigned int &hours)
{
	// System will auto recognize the current hour and give some suggestion for this time randomly
	if(hours == 12)// At lunch
	{
		vector <string> careLunch;
		careLunch.push_back("Nows is noon ... I thinks that It's time to have lunch !!!! Let suspend your LAPTOP and relax !!! ^^ ");
		careLunch.push_back("Haizzzz ..... I'm so tired now !!!! Can we stop your work and relax together !!!! @.@");
		careLunch.push_back("I'm hungry !!!!! I'm wanna eat !!!! it's 12 o'clock !!!! T.T");
		srand(time(NULL));
		int ran = rand() % careLunch.size();
		cout << REM_SYS << careLunch.at(ran) <<endl;
	}
	else if( hours >= 17 && hours <= 18)// At dinner 
	{
		cout << REM_SYS << "Hmmm !!!! " <<endl;
		sleep(2);
		cout << REM_SYS << "Your work have finished yet ???" << endl;
		sleep(1);
		vector <string> careDinner;
		careDinner.push_back("It's time to relax and come back home !!!! I'm waiting for you at our home !!!! ^^ ");
		careDinner.push_back("I'm so sad !!!! Please come home early !!!! T.T ");
		careDinner.push_back("Oh dear !!!! I'm so hungry right now !!!! I wanna we can have dinner together !!! ");
		srand(time(NULL));
		int ran = rand() % careDinner.size();
		cout << REM_SYS << careDinner.at(ran);
	}
}

/*Main function (use to fix bug)*/

int main()
{
	return 0;
}