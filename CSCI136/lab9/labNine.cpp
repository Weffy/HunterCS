/*
Title: lab nine
Created By: Krirk Pongsema
Created Date: 11/14/13
Description: QuBi Strings
Modified: 
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main()
{
	string strA, strB; 
	int choice; //for user input
	char finish = 'n'; //gives user option to quit and break loop

//input from file
	ifstream inputFile;
	inputFile.open("dna.txt");
	inputFile >> strA;
	inputFile >> strB;

//string lengths, will need later
	int aLength = strA.length();
	int bLength = strB.length();
	while (finish == 'n')
	{
		cout <<"Welcome to lab nine!"<<endl;
		cout <<"which part would you like to view?"<<endl;
		cout <<"1. Check if there is any unknown letters in any strings"<<endl;
		cout <<"2. Count the number of occurances of the character c for the first DNA strand"<<endl;
		cout <<"3. find the fraction (number of g's and c's) / (length of string) for second DNA strand"<<endl;
		cout <<"4. Count the number of occurrences of more consecutive t's for both strands"<<endl;
		cout <<"5. Count and report the positions at which the two DNA strands differ"<<endl;
		cout <<"6. quit"<<endl;
		cin >> choice;
		
		if (choice == 1)
		{
			cout <<"DNA String A"<<endl;
			for (int i = 0; i < aLength; i++)
			{
				if (strA[i] != 'a' && strA[i] != 'c' && strA[i] != 'g' && strA[i] != 't')
				{

					cout <<"unknown dna strand "<< strA[i]<< " found at index " << i << "."<<endl;
				}
			}
			cout <<"DNA String B"<<endl;
			for (int i = 0; i < bLength; i++)
			{

				if (strB[i] != 'a' && strB[i] != 'c' && strB[i] != 'g' && strB[i] != 't')
				{

					cout <<"unknown dna strand "<< strB[i]<< " found at index " << i << "."<<endl;
				}		
			}
		}	
	
		if (choice == 2)
		{
			int count = 0;
			for (int i = 0; i < aLength; i++)
			{
				if (strA[i] == 'c')
				{
					count++;
				}
			}
			cout << "c appears " << count << " time(s)"<<endl;
		}

		if (choice == 3)
		{

			int count = 0;
			for (int i = 0; i < aLength; i++)
			{
				if (strA[i] == 'c' || strA[i] == 'g')
				{
					count++;
				}
			}
			cout << count << " / " << aLength<<endl;			
		}

		if (choice == 4)
		{
			int count = 0;
			for (int i = 0; i < aLength; i++)
			{
				if (strA[i] == 't')
				{
					if (strA[i+1] == 't')
					{
						count++;
						i++;
					}
				}
			}
			cout << "after string A "<<count<<endl;
			for (int i = 0; i < bLength; i++)
			{
				if (strB[i] == 't')
				{
					if (strB[i+1] == 't')
					{
						count++;
						i++;
					}
				}				
			}
			cout << "after string B "<<count<<endl;
		}

		if (choice == 5)
		{
			for (int i = 0; i < aLength;i++)
			{
				if (strA[i] != strB[i])
				{
					cout <<"string A and string B differ at index: "<<i<<endl;
					cout <<"string A = "<<strA<<endl;
					cout <<"string B = "<<strB<<endl;
				}
			}
		}

		if (choice == 6)
		{
			finish = 'y';
			inputFile.close();
		}



	}
	inputFile.close();
	return 0;
}

