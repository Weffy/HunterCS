/*
Title: c-strings
Created By: Krirk Pongsema
Created Date: 11/26/13
Description: Lab eleven
Modified:
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int size(string a);
void compare(int x, int y);
void search(string q);
/*void partSearch(string q); ended up not needing this*/

int main()
{
	cout <<"welcome to lab 11 for csci136"<<endl;
	cout <<"part 1, write our own .length function"<<endl;
	cout <<"and show which string is longer"<<endl;
	string c1, c2;
	int choice, s1, s2;
	string done = "n";
	while (done == "n")
	{
		cout <<"Enter a string"<<endl;
		cin >> c1;
		cout <<"Enter another string"<<endl;
		cin >> c2;
		s1 = size(c1);
		s2 = size(c2);
		compare(s1,s2);
		cout <<"would you like to run this again?"<<endl;
		cout <<"1. yes"<<endl;
		cout <<"2. no"<<endl;
		cin >> choice;
		if (choice == 2)
		{
			done = "y";
		}
	}
	done = "n";
	ofstream out;
	while (done == "n")
	{
		cout <<"lab 11 part 2"<<endl;
		cout <<"What would you like to do?"<<endl;
		cout <<"1. make a new dictionary entry"<<endl;
		cout <<"2. search for a word"<<endl;
		cout <<"3. clear dictionary"<<endl;
		cout <<"4. quit"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			string word, def;
			out.open("dict.txt", ios::app); //remember to close!!!!
			cout <<"enter a word "<<endl;
			cin >> word;
			out << word;
			cout <<"enter the definition for "<< word<<endl;

			while (def.size() == 0)
//refrenced from http://stackoverflow.com/questions/19264187/getlinecin-input-with-multiple-lines-c
			{	
				getline(cin, def);
				out <<" " << def;
			}
			out << endl;
			out.close();
		}
		else if (choice == 2)
		{
			string query;
			cout <<"what word are you looking for: "<<endl;
			cin >> query;
			search(query);
		}
		else if (choice == 3)
		{
			out.open("dict.txt");
			out.close();
			cout <<"dictionary cleared."<<endl;
		}
		else if (choice == 4)
		{

			done = "y";
		}


	}
	

	  return 0;
}

int size(string a)
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}

void compare(int x, int y)
{
	if (x > y)
	{
		cout <<"the first string is larger by: " << x - y <<endl;
		cout <<endl;
	}
	else if (y > x)
	{
		cout <<"the second string is larger by: " << y - x <<endl;
		cout <<endl;
	}
	else if (x == y)
	{
		cout <<"the strings are equal in length"<<endl;
		cout <<endl;
	}
}


void search(string q)
//refrenced from http://www.cplusplus.com/forum/beginner/33615/
{
	ifstream in;
	in.open("dict.txt");
	string line;
	int loc;
	cout << "string q: "<< q <<endl;
	while (!in.eof())
	{
		getline(in, line);
		loc = line.find(q);
		if(loc != string::npos)
        	{
           		cout <<line<<endl;
			in.close();
			break;
    		}
	}
/*	if (loc == -1)
	{
		int choice;
		cout <<"no match was found"<<endl;
		cout <<"would you like to try a partial search?"<<endl;
		cout <<"1. yes"<<endl;
		cout <<"2. no"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			partSearch(q);
		}
		else if (choice == 2)
		{
			cout <<"returning to main menu."<<endl;

		}
	}
*/
}
/*
void partSearch(string q)
{
	int length = size(q);
	int position = length - 1;
	q.resize(position);
	search(q);
}

*/



