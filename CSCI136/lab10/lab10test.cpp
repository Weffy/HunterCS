/**********************************************************************
 Title:         : lab10test.cpp
 Author         : Krirk Pongsema
 Created on     : 11/19/2013
 Description    : lab10, testing all code in 1 file
 Purpose        : seeing if my errors are file linking or syntax, etc
 Modification   : Revised version 2. 9:30pm
 **********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Employee
{
	public:
		//constructor functions
		Employee();
		Employee(char s);
		//mutators
		void setupEmployee(class Employee w[]);
		void setSalary();
		void bonusManager();
		void setName();
		void setTitle();
		void setStatus();
		bool setID();
		//accessors
		int getID();
		string getName();
		string getTitle();
		char getStatus();
		double getSalary();
		void getEmpInf(); //just one employee
		void printEmpInf(); //all employees	
	private:
		int idnum;
		string name;
		string title;
		char status;
		double salary;
};



int main()
{
	//clears file of numbers from previous use
	ofstream clear;
	clear.open("idnum.txt"); 
	clear << "";
	clear.close();

	int NUMBER_OF_EMPLOYEES = 10;
	int choice;
	//sets up initial state
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
			for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++) //goes through each object and prints all information
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
				idcompare = scv[i].getID(); //gets the idnumber of the current object to compare with the search
				if (manager == idcompare)
				{
					rank = scv[i].getTitle();
					if (rank == "manager")//if the title is a manager, then it will grant a bonus
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
				if (worker == idcompare) //if it is a match, it will get the information requested
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

Employee::Employee()
{

}

Employee::Employee(char s) //sets status for employee
{
	status = s;
}

void Employee::setupEmployee(class Employee w[])
{
	bool check = false;
	while (check == false)
	{
		check = setID();
	}
	setName();
	setTitle();
	setStatus();
	setSalary();

}

void Employee::setSalary()
{
	cout <<"Salary?"<<endl;
	cin >> salary;	
}

void Employee::bonusManager()
{
	salary = salary * 1.20;
}

void Employee::setName()
{
	cout <<"Name?"<<endl;
	cin >> name;
}

void Employee::setTitle()
{
	cout <<"Title?"<<endl;
	cin >> title;
}

void Employee::setStatus()
{
	cout <<"Status?"<<endl;
	cin >> status;
}

bool Employee::setID()
{
	int idnumber;
	int idcompare;
	cout << "ID Number?"<<endl;
	cin >> idnumber;
	ifstream idcheckin;
	idcheckin.open("idnum.txt", ios::app);
	while (!idcheckin.eof())
	{
		idcheckin >> idcompare;
		if (idnumber == idcompare)
		{
			cout <<"ID number already exists"<<endl;
			return false;
		}
	}
	idcheckin.close();
	ofstream idcheckout;
	idcheckout.open("idnum.txt", ios::app);
	idcheckout << idnumber <<endl;
	idcheckout.close();
	idnum = idnumber;
	return true;
}

int Employee::getID()
{
	return idnum;
}

string Employee::getName()
{
	return name;
}

string Employee::getTitle()
{
	return title;
}

char Employee::getStatus()
{
	return status;
}

double Employee::getSalary()
{
	return salary;
}

void Employee::getEmpInf()
{
	cout <<endl;
	cout <<"Name: " << name<<endl;
	cout <<"ID#: " << idnum<<endl;
	cout <<"Title: "<<title<<endl;
	cout <<"Status: " <<status<<endl;
	cout <<"Salary: " <<salary<<endl;
	cout <<endl;	
}

void Employee::printEmpInf()
{
	cout <<endl;
	cout <<"Name: " << name<<endl;
	cout <<"ID#: " << idnum<<endl;
	cout <<"Title: "<<title<<endl;
	cout <<"Status: " <<status<<endl;
	cout <<"Salary: " <<salary<<endl;
	cout <<endl;
	
}
