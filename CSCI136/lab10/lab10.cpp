/**********************************************************************
 Title:         : lab10.cpp
 Author         : Krirk Pongsema
 Created on     : 11/19/2013
 Description    : driver file for lab10
 Purpose        : To practice class/object usage
                  Also to practice OOP programming
 Modification   : Revised version 1. 12:00pm
 **********************************************************************/
#include "emp.h"

int main()
{
	//clears file of numbers from previous use
	ofstream clear;
	clear.open("idnum.txt"); 
	clear << "";
	clear.close();

	int NUMBER_OF_EMPLOYEES = 10;
	int choice;
	cout <<"Initial setup"<<endl;
	cout <<"We will begin by setting up the employees"<<endl;
	Employee scv[NUMBER_OF_EMPLOYEES];
	for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
	{
		scv[i].setupEmployee(scv);
	}

	string done = "n";
	while (done == "n")
	{
		cout <<"What would you like to do?"<<endl;
		cout <<"1. print all information about employees"<<endl;
		cout <<"2. give a bonus to a manager."<<endl;
		cout <<"3. get information about a specific employee"<<endl;
		cout <<"4. quit"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
			{
				scv[i].printEmpInf();
			}
		}
		else if (choice == 2)
		{
			int manager;
			int idcompare;
			string rank;
			cout <<"which manager?"<<endl;
			cout <<"enter an ID number"<<endl;
			cin >> manager;
			for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
			{
				idcompare = scv[i].getID();
				if (manager == idcompare)
				{
					rank = scv[i].getTitle();
					if (rank == "manager")
					{
						scv[i].bonusManager();
					}
					else
					{
						cout <<"this ID number doesn't belong to a manager"<<endl;
					}
				}
			}						
		}
		else if (choice == 3)
		{
			int worker;
			int idcompare;
			cout <<"which employee?"<<endl;
			cout <<"enter an ID number"<<endl;
			cin >> worker;
			for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++)
			{
				idcompare = scv[i].getID();
				if (worker == idcompare)
				{
					scv[i].getEmpInf();
				}
	
			}
		}
		else if (choice == 4)
		{
			done = "y";
		}
	}

	return 0;
}
