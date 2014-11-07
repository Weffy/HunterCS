/*
Krirk Pongsema
CSCI135
Homework #2
Ch. 2, Question 4.
*/

#include <iostream>
using namespace std;

int main()
{

	int check = 3;

//outside loop to cycle through numbers			
	while (check <= 100)
	{

//needed these vars to reset to the original values
		int count = 0;
		int x = 1;

//inside loop to do the actual check if it is prime
		while (check >= x)
		{
			if (check % x == 0)
			{
				count++;
				x++;
			}
			else
			{
				x++;
			}
			
			
		}

//count is for the actual number of times we find a number that divides it perfectly
//if it is greater than 2 numbers, it is not prime.		
		if (count == 2)
		{
			cout << check <<endl;
			check++;
		}	
		else 
		{
		check++;
		}
	}
	



	return 0;
}
