#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int vecInputSize;
	string stuffIn;
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("krirk_text.txt");
	vector<string>vecInput;
	string done = "n";
	int choice;
	while (done == "n")
	{
		cout << "would you like to clear krirk_output.txt"<<endl;
		cout << "from previous run?"<<endl;
		cout << "(1) Yes"<<endl;
		cout << "(2) No" <<endl;
		cin >> choice;
		if (choice == 1)
		{
			done = "y";
			outputFile.open("krirk_output.txt");
			outputFile.close();
		}
		else if (choice == 2)
		{
			done = "y";
		}
	}
//filling the vector
	while (!inputFile.eof())
	{
		inputFile >> stuffIn;
		vecInput.push_back(stuffIn);	
	}
	vecInputSize = vecInput.size() - 1;
	for (int i = 0; i < vecInputSize; i++)
	{
		if(vecInput[i] == "hate")
		{
			vecInput[i] = "love";
		}
	}
//output to file

	outputFile.open("krirk_output.txt", ios::app);
	outputFile << "there are " << vecInputSize << " words, and they are: ";
	for (int i = 0; i < vecInputSize;i++)
	{

		outputFile << vecInput[i] << " ";
	}
/*
//testing vector
	for (int i = 0; i < vecInputSize;i++)
	{
		cout << vecInput[i] << endl;
	}
*/


	inputFile.close();
	outputFile.close();
	return 0;
}
