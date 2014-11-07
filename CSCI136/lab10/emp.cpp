/**********************************************************************
 Title:         : emp.cpp
 Author         : Krirk Pongsema
 Created on     : 11/19/2013
 Description    : implementation file for lab10
 Purpose        : define member functions
 Modification   : Revised version 1. 12:00pm
 **********************************************************************/
#include "emp.h"

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
