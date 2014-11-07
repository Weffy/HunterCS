/*
Title: lab eight
Created By: Krirk Pongsema
Created Date: 11/5/13
Description: 
Modified: 
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
#include "labEight.h"



// guest structure
struct Groups
{
	int gSize;
	char location1;
	char location2;
	char where; //needed this so the function would stop looking at groups who were sitting already.
};

const int NUMTABLES = 25; // number of tables
const int NUMGROUPS = 10; // number of groups
// main function
int main()
{
	int choice;
	string done = "n";
//table vars
	int n; //name
	int s; // capacity of table
	int st; //if the table is free or not
	char loc; //location of table (i, w, o)

//group vars
	int groupSize; //group size
	char loc1; //preferred table location
	char loc2; //backup selection for table
	char donde;

//create objects for stream
	ifstream inputTableFile;
	inputTableFile.open ("table.txt");
	ifstream inputGuestFile;
	inputGuestFile.open("guest.txt");

	if (inputGuestFile.fail())
	{
		cout <<"unable to open guest file"<<endl;
	}
	if (inputTableFile.fail())
	{
		cout <<"unable to open table file"<<endl;
	}
//object arrays
	Table tab[NUMTABLES];
	Groups grp[NUMGROUPS];	


//fills table objects with data from txt file
	for (int i=0; i<NUMTABLES; i++)
	{
		inputTableFile >> n >> loc >> s >> st;
		tab[i].setTable(n, loc, s, st);
	}
	inputTableFile.close();

//fills grp object with data from txt file
	for (int i = 0; i<NUMGROUPS; i++)
	{
		inputGuestFile >> groupSize >> loc1 >> loc2 >> donde;	 
		grp[i].gSize = groupSize;
		grp[i].location1 = loc1;
		grp[i].location2 = loc2;
		grp[i].where = donde;   
		cout <<"group "<<i<<" " <<grp[i].gSize<<" "<<grp[i].location1<<" "<<grp[i].location2<<" " <<grp[i].where<<endl;
	}
	inputGuestFile.close();

	while (done != "y")
	{
		cout << "what would you like to do?"<<endl;
		cout << "1: check the status of a table"<<endl;
		cout << "2. see status of all the tables"<<endl;
		cout << "3. clear a table"<<endl;
		cout << "4. go through guest list and assign table"<<endl;
		cout << "5. quit"<<endl;
		cin >> choice;
		if (choice == 1) //check status of 1 table
		{
			int i = 0;
			cout <<"which table?"<<endl;
			cout <<"please enter a number"<<endl;
			cin >> i;
			i = i + 1;
			tab[i].checkTable();
		}
		else if (choice == 2) //check status of all tables
		{
			for (int j=0; j<NUMTABLES; j++) //lists table information
			{
				tab[j].drawTable();
			}
		}
		else if (choice == 3) //clears a table
		{
			int i = 0;
			cout <<"which table would you like to make available?"<<endl;
			cout <<"please enter a number"<<endl;
			cin >> i;
			i = i + 1;
			tab[i].freeTable();
			cout <<"table "<< i <<endl;
		}
		else if (choice == 4)
		{
			
			for (int i = 0; i < NUMTABLES; i++)
			{
				bool stat = tab[i].getStatus();
				if (stat == 1) //table is available
				{
					tab[i].assignTable(grp);
				}
			}
		}
		else if (choice == 5) //quit
		{
			cout << "enjoy your meal!"<<endl;
			done = "y";
		}		
	}



		


	return 0;
}

void Table::checkTable() //check if status is true (1) / false (0)
{
	if (status == 1)
	{
		cout <<"the table is free"<<endl;
	}
	else if (status == 0)
	{
		cout <<"the table is occupied"<<endl;
	}
}

void Table::freeTable() //set status to true (1) (available)
{
	status = 1;

}

void Table::setTable(int name, char location, int size, bool status)
{
	this-> name = name;
	this-> location = location;
	this-> size = size;
	this-> status = status;

}

bool Table::getStatus()
{
	return status;
}

int Table::getName()
{
	return name;
}

char Table::getLocation()
{
	return location;
}

void Table::drawTable()
{
	cout << "\nTable name is: " << name <<endl;
	cout << "Table location is: " << location <<endl;
	cout << "Table status is: " << status <<endl;
	cout << "Table size is: " << size <<endl;
}

void Table::assignTable(struct Groups g[])
{
	for (int i = 0; i < NUMGROUPS; i++)
	{
		if (g[i].where == 'b')
		{
			if ((g[i].location1 == location || g[i].location1 == 'a') && g[i].gSize <= size)
//does location match OR does customer care where they sit AND does the size of the party fit the table
			{
				status = 0;
				cout <<"group " << i+1<< " seated at table " <<name<<endl;
				g[i].where = 's'; //seated
				break;
			}
			else if ((g[i].location2 == location || g[i].location2 == 'a') && g[i].gSize <= size)
//does location match OR does customer care where they sit AND does the size of the party fit the table
			{
				status = 0;
				cout <<"group " << i+1<< " seated at table " <<name<<endl;
				g[i].where = 's'; //seated
				break;
			}
		}

	}
}

