/*
Title: Day of the week calculator
Created By: Krirk Pongsema
Created Date: 9/27/13
Description: Homework #3
Modified:
Modified Date: 
Modified By:
*/ 

/*
Things to add!

1 convert inputMonth to string
2 convert string to all caps
3 read string
4 convert string to corresponding number
5 

*/
#include <iostream>
#include <string>

using namespace std;

//function declarations
bool isLeapYear (int year);
int getCenturyValue (int year);
int getYearValue (int year);
int getMonthValue (int month, int year);

int main()
{

//vars
	string strMonth;
	int inputMonth = 13;
	int inputYear;
	int inputDate;
	bool leapYear;
	int centYear;
	int yearYear; //didnt know what else to name it! 
	int month;
	int sum;



//if block to convert string to corresponding numerical value
//while loop to ensure a value is selected
	while (inputMonth > 12)
	{
		cout << "Please enter the month: "<<endl;
		cin >> strMonth;
		if (strMonth == "January" || strMonth == "january" || strMonth == "JANUARY")
		{
			inputMonth = 1;	
		}
		else if (strMonth == "February"|| strMonth == "february" || strMonth == "FEBRUARY")
		{
			inputMonth = 2;	
		}
		else if (strMonth == "March"|| strMonth == "march" || strMonth == "MARCH")
		{
			inputMonth = 3;	
		}
		else if (strMonth == "April"|| strMonth == "april" || strMonth == "APRIL")
		{
			inputMonth = 4;	
		}
		else if (strMonth == "May"|| strMonth == "may" || strMonth == "MAY")
		{
			inputMonth = 5;	
		}
		else if (strMonth == "June"|| strMonth == "june" || strMonth == "JUNE")
		{
			inputMonth = 6;	
		}
		else if (strMonth == "July"|| strMonth == "july" || strMonth == "JULY")
		{
			inputMonth = 7;	
		}
		else if (strMonth == "August"|| strMonth == "august" || strMonth == "AUGUST")
		{
			inputMonth = 8;	
		}
		else if (strMonth == "September"|| strMonth == "september" || strMonth == "SEPTEMBER")
		{
			inputMonth = 9;	
		}
		else if (strMonth == "October"|| strMonth == "october" || strMonth == "OCTOBER")
		{
			inputMonth = 10;	
		}
		else if (strMonth == "November"|| strMonth == "november" || strMonth == "NOVEMBER")
		{
			inputMonth = 11;	
		}
		else if (strMonth == "December"|| strMonth == "december" || strMonth == "DECEMBER")
		{
			inputMonth = 12;	
		}
	}
	//input
	cout << "Please enter the date: ";
	cin >> inputDate;
	cout << "Please enter the year: ";
	cin >> inputYear;
//function calls
	leapYear = isLeapYear (inputYear);
	centYear = getCenturyValue (inputYear);
	yearYear = getYearValue (inputYear);
	month	 = getMonthValue (inputMonth, inputYear);
	
	
//calculations
	sum = inputDate + month + yearYear + centYear;
	sum = sum % 7;
	
//if block for day of the week and output
	if (sum == 0)
	{
		cout << "Sunday"<<endl;	
	}
	else if (sum == 1)
	{
		cout << "Monday"<<endl;	
	}
	else if (sum == 2)
	{
		cout << "Tuesday"<<endl;	
	}
	else if (sum == 3)
	{
		cout << "Wednesday"<<endl;	
	}
	else if (sum == 4)
	{
		cout << "Thursday"<<endl;	
	}
	else if (sum == 5)
	{
		cout << "Friday"<<endl;	
	}
	else
	{
		cout << "Saturday"<<endl;
	}

	return 0;
}

//function definitions
bool isLeapYear (int inputYear)
{
	bool leapYear = ((inputYear % 400 == 0) || (inputYear % 4 == 0 && inputYear % 100 != 0));
	if (leapYear = true)
	{
		return 	true;
	} 
	else
	{
		return false;
	}
}

int getCenturyValue (int inputYear)
{
	int centValue = inputYear / 100;
	centValue = centValue % 4;
	centValue = 3 - centValue;
	return centValue * 2;
}

int getYearValue (int inputYear)
{
	int yearValue = inputYear % 100;
	int temp = yearValue;
	yearValue = yearValue / 4;
	return temp + yearValue;
	
}

int getMonthValue (int inputMonth, int inputYear)
{
	if (inputMonth == 1) //january
	{
		if (isLeapYear(inputYear) == true)
		{
			return 6;
		}
		else
		{
			return 0;
		}
		
	}
	if (inputMonth == 2) //february
	{
		if (isLeapYear(inputYear) == true)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	if (inputMonth == 3 || inputMonth == 11) //march or november
	{
		return 3;
	}
	if (inputMonth == 4 || inputMonth == 7) //april or july
	{
		return 6;
	}
	if (inputMonth == 5) //may
	{
		return 1;
	}
	if (inputMonth == 6) //june
	{
		return 4;
	}
	if (inputMonth == 8) //august
	{
		return 2;
	}
	if (inputMonth == 9 || inputMonth == 12) //september or december
	{
		return 5;
	}
	if (inputMonth == 10) //october
	{
		return 0;
	}
}

