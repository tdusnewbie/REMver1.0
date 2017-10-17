////////////////////// Finish all at Thursday,September 28th 2017, 22:00 ////////////////////////
////////////////////// Fixing all bugs at Thursday,September 28th 2017, 23:30 ////////////////////////


/*Support Function*/
//Function in here use to support for say Hello function and some task for main function

//Check type of Hello and classify them (have two types :Special=>good morning/good afternoon and Normal)
bool checkTypeSentences(string command)
{
	vector <string> temp;
	temp.push_back("good morning");
	temp.push_back("good afternoon");
	temp.push_back("good evening");
	for(int i =0;i<3;i++)
	{
		if(command.compare(temp[i])==0)
		{
			return true;
		}
	}
	return false;
}


// Classify and check command with current time (Ex: "good morning" is true at morning) 
bool checkTimeWithCommand(string command, unsigned int hours)
{
	vector <string> temp;
	temp.push_back("good morning");
	temp.push_back("good afternoon");
	temp.push_back("good evening");
	if(hours >18 && command.compare(temp.at(2))==0)
		return true;
	else if(hours >12 && hours <= 18 && command.compare(temp.at(1))==0)
		return true;
	else if(hours >6 && hours<12 && command.compare(temp.at(0))==0)
		return true ;
	else 
		return false;
}


/*Say Hello Function*/
//When system recieves hello sentence from user ... it will answer this one by special or normal way
void sayHello(string &command, unsigned int &hours)
{
	// Connect and read file helloINPUT.txt and helloOUTPUT.txt 
	ifstream output ("/root/REMver1.0/REMfile/helloOUTPUT.txt");
	ifstream input ("/root/REMver1.0/REMfile/helloINPUT.txt");
	if(output.is_open() && input.is_open()) // If above files exist, system will execute functions below
	{
		//Create vetor array to content all the way answer
		vector <string> outPut;
		string temp;
		while(getline(output,temp))
		{
			outPut.push_back(temp);
		}
		output.close();// close file if above array have finished adding sentence

		//compare and classify input sentence
		while(getline(input,temp))
		{
			// Check type of sentence 
			bool checkType = checkTypeSentences(command); 
			//Classify hello sentences
			if(command == temp && checkType == false)
			{
				// Case 1: If above conditions are wrong ... system will answer by the normal way
				srand(time(NULL));
				int ran = rand()% + outPut.size();
				cout << REM_SYS << outPut.at(ran) << endl;
			}
			if(command == temp && checkType == true)
			{			
				// Case 2: If they are right .... system will continuously check and compare comand and time
				bool check = checkTimeWithCommand(command,hours);
				//Recognize if checking command is right or wrong
				if(check == true)
				{
					//Case 1: if checking is right ... system will use as the same as the normal way to say hello
					srand(time(NULL));
					int ran = rand()% + outPut.size();
					cout << REM_SYS <<outPut.at(ran) << endl;
				}
				else if(check == false)
				{
					//Case 2: if checking is wrong ..... system will answer with some sentences have been added before by developer
					vector <string> outputSpecial;
					outputSpecial.push_back("OMG ..... Are you OK My Boss ???? .... PLease check time again !!!");
					outputSpecial.push_back("Haizzzz .... I think now you are so tired .... So .. You need to relax a bit !!! My Boss ^^");
					outputSpecial.push_back("What are you talking about !!");
					srand(time(NULL));
					int ran = rand()% + outputSpecial.size();
					cout << REM_SYS << outputSpecial.at(ran) <<endl;
				}

			}
		}
		// After that .... finish hello process and close file helloINPUT.txt
		input.close();
	}
}

/*Main Function to fix bugs*/

/*int main()
{
	string command;
	cout<<USER;
	getline(std::cin,command);
	sayHelloCommon(command);
	return 0;
}*/