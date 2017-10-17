//////////////////////// Finish All at Tuesday, October 3rd, 2017 19h30 //////////////////////// 
//////////////////////// Fixing All bugs at Wednesday, October 4th, 18h30 ////////////////////////


/* Learn new conversation Function */
//At this function ... system will allow user to teach program some new conversation if it can not find suitable answer for user's command

//Save new INPUT Function (it means what type of this command)

void saveFileInPut(ofstream &file, string &command)
{
	int choose;
	string temp;
	while (1) // system will save user command into file and continue with another type of this command
	{
		command += '_';/// "_"  use to classify type of users command
		cout << REM_SYS << "Do you want to add different way to say this conversation (1:Yes/0:No) ???"<<endl;
		cout << USER ;
		cin >> choose;
		if(choose == 0) // If user don't have any type else
		{
			break;
		}
		else if(choose == 1) //If choose is 1 .... user can input different type of this command 
		{
			cin.ignore(); 
			cout << REM_SYS << "PLease enter your statement : " << endl;
			cout << USER ;
			getline(std::cin,temp);
			command += temp;  
		}
		else // If choose is not 1 and 0 ... system will understand that user choose 0
		{
			cout << REM_SYS << "Your choise has not existed in my suggestions .. So i will run with choose is 0 !!! ^^ "<<endl;
			break;
		}
	}
	// After that ... save all into file chatINPUT.txt
	file << command <<endl;
}

// Save new OutPut coversation Function

void saveFileOutPut(ofstream &file)
{
	int choose;
	string temp;
	string temp2;
	cin.ignore();
	// User must be enter the answer for his/her input if he/she has teach system new conversation
	cout << REM_SYS << "So ..... How can I reply to you with this statement ???? Can you give me some suggestions ?? @@ " << endl;
	cout << USER ;
	getline(std::cin,temp);
	temp2 += temp;
	while (1) // Add another answer's type
	{
		//In here, all of step is same as "Save new Input conversation Function .... So i will not explain anymore"
		cout << REM_SYS << "Do you wanna continue giving me some ways else (1:Yes/0:No) ?? " << endl;
		cout << USER ;
		cin >> choose;
		if(choose == 0)
		{
			temp2 += '_';
			break;
		}
		else if(choose == 1)
		{
			temp2 += '_';
			string temp3;
			cin.ignore();
			cout<< REM_SYS << " PLease enter your statement " << endl;
			cout << USER;
			getline(std::cin,temp3);
			temp2 += temp3;
		}
		else 
		{
			cout << REM_SYS << "Your choise has not existed in my suggestions .. So i will run with choose is 0 !!! ^^ "<<endl;
			temp2 += '_';
			break;
		}
	}
	file << temp2 << endl;
}

// Learn New Conversation Function (Main of three)
void learnNewConversation(string &command)
{
	// Connect and eopen two file chatINPUT.txt and chatOUTPUT.txt
	ofstream putFileInPut ("/root/REMver1.0/REMfile/chatINPUT.txt",ios::app); 
	ofstream putFileOutPut ("/root/REMver1.0/REMfile/chatOUTPUT.txt",ios::app); 

	// If user wanna teach program new conversation ... system will run two function below
	saveFileInPut(putFileInPut,command);
	saveFileOutPut(putFileOutPut);
	cout << REM_SYS << "Hmmmm !!! ........... " << endl;
	sleep(2);
	//Create some answer's type when finish teaching 
	vector <string> outputAfterLearn;
	outputAfterLearn.push_back("Wow !!! Today I have been able to learn so much !!!! Love you so much ... My Boss !! ");
	outputAfterLearn.push_back("I believe in that what you have taught me today will be very helpful for me in the future !!!! ^^ ");
	outputAfterLearn.push_back("OK ... Now I think I have remember all your lesson !!!! Ahaha..... I am very genius ,Right ???? Ahaha =) ");
	//Auto answer with one of type in above vector array
	srand(time(NULL));
	int ran = rand()% + outputAfterLearn.size();
	cout << REM_SYS << outputAfterLearn.at(ran) <<endl;
	// After that ... system will close all file
	putFileOutPut.close();
	putFileInPut.close();
}


/*Recognize User'Input Function*/

int recognizeInPut(string command)
{
	string tempAll;
	string tempPart;
	int rowsInPut = 0;
	// Connect and open file chatINPUT.txt
	ifstream getFileInPut ("/root/REMver1.0/REMfile/chatINPUT.txt");
	if(getFileInPut.is_open()); // If that file exists 
	{
		while(getline(getFileInPut,tempAll)) //Check and find in chatINPUT.txt sentence is same as User's command
		{
			size_t found = tempAll.find(command);
			rowsInPut ++;
			if(found != std::string::npos) // If that command exists in File
			{
				getFileInPut.close();
				return rowsInPut; // Close file and return number of row has that one
			}
		}
		// If that command doesn't exist  
		getFileInPut.close(); // close file and suggest user teaching this sentence 
		cout << REM_SYS << "Hmmm !! ........" <<endl;
		sleep(2);
		cout << REM_SYS << "Maybe ..... I don't know this statement ... So ... Can I learn this (1:Yes/0:No) ?????? "<<endl;
		cout << USER ;
		int choose;
		cin >> choose;
		if(choose == 1) // If user agrees with this suggestion
		{
			learnNewConversation(command); // Begin teaching
			return 0;
		}
		else if (choose == 0) // If users disagrees with teaching sugestion
		{
			//Ask google about that command
			string google = "googler ";
			google += command;
			system(google.c_str());
			return 0;
		}
		else // If user's choice is not 0 or 1 ... system will understand this is 0
		{
			cout << REM_SYS << "Your choise has not existed in my suggestions .. So i will run with choose is 0 !!! ^^ "<<endl;
			sleep(1);
			string google = "googler ";
			google += command;
			system(google.c_str());
			return 0;
		}
	}
}


/*Auto answer Function*/
//This function use to answer when system can recognize command of user randomly

// move poiter to suitable rows Function (number of row in input must be same as another one in output)
string takeStringOfRowInFile(ifstream &file, int rows)
{
	int tempRow =1;
	string temp;
	while(getline(file,temp))
	{
		if(tempRow<rows)
			tempRow++;
		else 
			break;
	}
	return temp; // After execute above process ... system will return sentence has contented answer
}

//Answer conversation randomly Function (main of two)
string randomOutPut (int rowsInPut)
{
	// connect and read file chatOUTPUT.txt
	ifstream getFileOutPut ("/root/REMver1.0/REMfile/chatOUTPUT.txt");
	string temp;
	vector <string> output;
	// Create array contenting all ways to answer and output randomly
	temp = takeStringOfRowInFile(getFileOutPut,rowsInPut);
	size_t flag = 0;
	size_t pos = temp.find_first_of('_');
	while(pos != std::string::npos)
	{
		output.push_back(temp.substr(flag,pos-flag));
		flag = pos+1;
		pos = temp.find_first_of('_',pos+1);
	}
	srand(time(NULL));
	int ran = rand()% + output.size();
	getFileOutPut.close();
	return output.at(ran);
}

/*Main function to fix bug*/


/*int main()
{
	cin.ignore();
	while(1)
	{
		string command;
		cout << USER;
		getline(std::cin, command);
		int rows = recognizeInPut(command);
		cout << rows << endl;
		if(rows == 0)
		{
			return 0;
		}
		else 
		{
			string temp = randomOutPut(rows);
			cout << REM_SYS << temp << endl;
		}
	}	
	return 0;
}*/