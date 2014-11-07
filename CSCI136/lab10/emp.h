/**********************************************************************
 Title:         : emp.h
 Author         : Krirk Pongsema
 Created on     : 11/19/2013
 Description    : header file for lab10
 Purpose        : define class and its members
 Modification   : Revised version 1. 12:00pm
 **********************************************************************/
#ifndef EMP_H
#define EMP_H
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


#endif
