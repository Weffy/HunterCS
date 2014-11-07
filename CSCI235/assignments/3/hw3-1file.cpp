 /**********************************************************************
 Title:         : sortingAlgs-v2.cpp
 Author         : Krirk Pongsema
 Created on     : 3/14/2014
 Description    : Applies different sorting algorithms to various sized
		  arrays and outputs the time needed.
 Purpose        : To study the difference between the different sorting
		  functions and how fast/slow they work depending on the
		  size of the array.
 Changelog	:
 Version 1:
 3/14/2014: shell setup.  need to populate functions/loops/conditionals
 3/16/2014: import/export to file and menu choices setup.  populate
	    functions work. need to import sorting algorithms.  clock
	    not working.
 3/17/2014: clock still not working.  quick sort and insertion sort
	    implemented.  need the other sorting algorithms.  need to
	    implement template so the functions can accept something
	    other than an integer. need to find the seg fault!!!!!
 3/18/2014: seg fault found.  scaled down the number of random numbers
	    from 100, 1 mil, 10 mil to 100, 1,000 , 1 mil.
	    implemented the rest of the sorting algorithms.
	    still need a clock and the template
 Version 2:
 3/19/2014: clock and template implemented
	    merge sort with 1 million hangs.  not sure why.
 3/21/2014: Had to swap 1 million to 100,000.  seems to fix the problem
	    with the compiler "hanging".  The clock doesn't work 
	    correctly with small arrays (100 & 1000) seems to work fine 
	    with 100,000 elements.
 3/22/2014: I want to find a larger number than 100,000.  Merge sort 
	    seems to be behaving now.  My problem seems to be with 
	    Selection sort.
 3/23/2014: 250,000 seems to be the magic number.  Adding a 4th option
	    for array size.  user will be given the options of: 100,
	    1000, 100,000, 250,000.  added new functions to fill array,
	    generate a 4th txt file with random numbers etc.
 3/24/2014: Separated into separate files for encapsulation.  obtained
	    data for table and chart.
 ***********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

/***************
Global Variables
***************/
const int ONE_HUNDRED = 100;
const int ONE_THOUSAND = 1000;
const int ONE_HUNDRED_THOUSAND = 100000;
const int TWO_HUNDRED_FIFTY_THOUSAND = 250000;
/**********************
functions to populate
the txt files using RNG
**********************/

void populateTxtOne();
void populateTxtTwo();
void populateTxtThree();
void populateTxtFour();
template<class T>
void populateArray(T theArray[], int size);
template<class T>
void printArray(T theArray[], int size);
/*********
Quick Sort
*********/
template<class T>
void quickSort(T theArray[], int first, int last);
template<class T>
int partition(T theArray[], int first, int last);
/*************
Insertion Sort
*************/
template<class T>
void swapValues(T& x, T& y); // swap two numbers
template<class T>
void insertionSort(T a[],int size); // sort the array
/*********
Merge Sort
*********/
template<class T>
void merge(T theArray[], int first, int mid, int last);
template<class T>
void mergeSort(T theArray[], int first, int last);
/*************
Selection Sort
*************/
template<class T>
int findIndexOfLargest(T a[], int s);
template<class T>
void selectionSort(T arr[], int size);
/**********
Bubble Sort
**********/
template<class T>
void bubbleSort(T a[], int size);
/*****************
Revised Quick Sort
*****************/
template<class T>
int findMidPivot(T theArray[], int first, int last);
template<class T>
void quickSort2(T theArray[], int first, int last);
template<class T>
int partition2(T theArray[], int first, int last);

int main()
{
	srand(time(NULL));
	populateTxtOne();
	populateTxtTwo();
	populateTxtThree();
	populateTxtFour();
	bool done = false;
	int menuChoice = 0;
/****
clock
****/
	clock_t start, end;
	double duration;


	while (!done)
	{
		cout <<"Sorting algorithms"<<endl;
		cout <<"which algorithm would you like to test?"<<endl;
		cout <<"(1) Quick Sort"<<endl;
		cout <<"(2) Insertion Sort"<<endl;
		cout <<"(3) Merge Sort"<<endl;
		cout <<"(4) Selection Sort"<<endl;
		cout <<"(5) Bubble Sort"<<endl;
		cout <<"(6) Quick Sort - v2"<<endl;
		cout <<"(7) Quit"<<endl;
		cin >> menuChoice;
		if (menuChoice == 1)
		{
			int elements;
			cout <<"How many elements in the array?"<<endl;
			cout <<"(1) 100"<<endl;
			cout <<"(2) 1,000"<<endl;
			cout <<"(3) 100,000"<<endl;
			cout <<"(4) 250,000"<<endl;
			cin >> elements;
			if (elements == 1)
			{
				start = clock();
				int theArray[ONE_HUNDRED];
				populateArray(theArray, ONE_HUNDRED);
				quickSort(theArray, 0, ONE_HUNDRED);
				printArray(theArray, ONE_HUNDRED);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC<< " seconds"<<endl;
			}
			else if (elements == 2)
			{
				start = clock();
				int theArray[ONE_THOUSAND];
				populateArray(theArray, ONE_THOUSAND);
				quickSort(theArray, 0, ONE_THOUSAND);
				printArray(theArray, ONE_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 3)
			{
				start = clock();
				int theArray[ONE_HUNDRED_THOUSAND];
				populateArray(theArray, ONE_HUNDRED_THOUSAND);
				quickSort(theArray, 0, ONE_HUNDRED_THOUSAND);
				printArray(theArray, ONE_HUNDRED_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 4)
			{
				start = clock();
				int theArray[TWO_HUNDRED_FIFTY_THOUSAND];
				populateArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				quickSort(theArray, 0, TWO_HUNDRED_FIFTY_THOUSAND);
				printArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}

		}
		else if (menuChoice == 2)
		{
			int elements;
			cout <<"How many elements in the array?"<<endl;
			cout <<"(1) 100"<<endl;
			cout <<"(2) 1,000"<<endl;
			cout <<"(3) 100,000"<<endl;
			cout <<"(4) 250,000"<<endl;
			cin >> elements;
			if (elements == 1)
			{
				start = clock();
				int theArray[ONE_HUNDRED];
				populateArray(theArray, ONE_HUNDRED);
				insertionSort(theArray, ONE_HUNDRED);
				printArray(theArray, ONE_HUNDRED);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 2)
			{
				start = clock();
				int theArray[ONE_THOUSAND];
				populateArray(theArray, ONE_THOUSAND);
				insertionSort(theArray, ONE_THOUSAND);
				printArray(theArray, ONE_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 3)
			{
				start = clock();
				int theArray[ONE_HUNDRED_THOUSAND];
				populateArray(theArray, ONE_HUNDRED_THOUSAND);
				insertionSort(theArray, ONE_HUNDRED_THOUSAND);
				printArray(theArray, ONE_HUNDRED_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 4)
			{
				start = clock();
				int theArray[TWO_HUNDRED_FIFTY_THOUSAND];
				populateArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				insertionSort(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				printArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}

		}
		else if (menuChoice == 3)
		{
			int elements;
			cout <<"How many elements in the array?"<<endl;
			cout <<"How many elements in the array?"<<endl;
			cout <<"(1) 100"<<endl;
			cout <<"(2) 1,000"<<endl;
			cout <<"(3) 100,000"<<endl;
			cout <<"(4) 250,000"<<endl;
			cin >> elements;
			if (elements == 1)
			{
				start = clock();
				int theArray[ONE_HUNDRED];
				populateArray(theArray, ONE_HUNDRED);
				mergeSort(theArray, 0, ONE_HUNDRED-1);
				printArray(theArray, ONE_HUNDRED);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 2)
			{
				start = clock();
				int theArray[ONE_THOUSAND];
				populateArray(theArray, ONE_THOUSAND);
				mergeSort(theArray, 0, ONE_THOUSAND-1);
				printArray(theArray, ONE_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 3)
			{
				start = clock();
				int theArray[ONE_HUNDRED_THOUSAND];
				populateArray(theArray, ONE_HUNDRED_THOUSAND);
				mergeSort(theArray, 0, ONE_HUNDRED_THOUSAND-1);
				printArray(theArray, ONE_HUNDRED_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 4)
			{
				start = clock();
				int theArray[TWO_HUNDRED_FIFTY_THOUSAND];
				populateArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				mergeSort(theArray, 0, TWO_HUNDRED_FIFTY_THOUSAND-1);
				printArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}

		}
		else if (menuChoice == 4)
		{
			int elements;
			cout <<"How many elements in the array?"<<endl;
			cout <<"How many elements in the array?"<<endl;
			cout <<"(1) 100"<<endl;
			cout <<"(2) 1,000"<<endl;
			cout <<"(3) 100,000"<<endl;
			cout <<"(4) 250,000"<<endl;
			cin >> elements;
			if (elements == 1)
			{
				start = clock();
				int theArray[ONE_HUNDRED];
				populateArray(theArray, ONE_HUNDRED);
				selectionSort(theArray, ONE_HUNDRED);
				printArray(theArray, ONE_HUNDRED);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 2)
			{
				start = clock();
				int theArray[ONE_THOUSAND];
				populateArray(theArray, ONE_THOUSAND);
				selectionSort(theArray, ONE_THOUSAND);
				printArray(theArray, ONE_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 3)
			{
				start = clock();
				int theArray[ONE_HUNDRED_THOUSAND];
				populateArray(theArray, ONE_HUNDRED_THOUSAND);
				selectionSort(theArray, ONE_HUNDRED_THOUSAND);
				printArray(theArray, ONE_HUNDRED_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;

			}
			else if (elements == 4)
			{
				start = clock();
				int theArray[TWO_HUNDRED_FIFTY_THOUSAND];
				populateArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				selectionSort(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				printArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;

			}

		}
		else if (menuChoice == 5)
		{
			int elements;
			cout <<"How many elements in the array?"<<endl;
			cout <<"(1) 100"<<endl;
			cout <<"(2) 1,000"<<endl;
			cout <<"(3) 100,000"<<endl;
			cout <<"(4) 250,000"<<endl;
			cin >> elements;
			if (elements == 1)
			{
				start = clock();
				int theArray[ONE_HUNDRED];
				populateArray(theArray, ONE_HUNDRED);
				bubbleSort(theArray, ONE_HUNDRED);
				printArray(theArray, ONE_HUNDRED);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 2)
			{
				start = clock();
				int theArray[ONE_THOUSAND];
				populateArray(theArray, ONE_THOUSAND);
				bubbleSort(theArray, ONE_THOUSAND);
				printArray(theArray, ONE_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 3)
			{
				start = clock();
				int theArray[ONE_HUNDRED_THOUSAND];
				populateArray(theArray, ONE_HUNDRED_THOUSAND);
				bubbleSort(theArray, ONE_HUNDRED_THOUSAND);
				printArray(theArray, ONE_HUNDRED_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 4)
			{
				start = clock();
				int theArray[TWO_HUNDRED_FIFTY_THOUSAND];
				populateArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				bubbleSort(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				printArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}

		}
		if (menuChoice == 6)
		{
			int elements;
			cout <<"How many elements in the array?"<<endl;
			cout <<"How many elements in the array?"<<endl;
			cout <<"(1) 100"<<endl;
			cout <<"(2) 1,000"<<endl;
			cout <<"(3) 100,000"<<endl;
			cout <<"(4) 250,000"<<endl;
			cin >> elements;
			if (elements == 1)
			{
				start = clock();
				int theArray[ONE_HUNDRED];
				populateArray(theArray, ONE_HUNDRED);
				quickSort2(theArray, 0, ONE_HUNDRED);
				printArray(theArray, ONE_HUNDRED);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 2)
			{
				start = clock();
				int theArray[ONE_THOUSAND];
				populateArray(theArray, ONE_THOUSAND);
				quickSort2(theArray, 0, ONE_THOUSAND);
				printArray(theArray, ONE_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 3)
			{
				start = clock();
				int theArray[ONE_HUNDRED_THOUSAND];
				populateArray(theArray, ONE_HUNDRED_THOUSAND);
				quickSort2(theArray, 0, ONE_HUNDRED_THOUSAND);
				printArray(theArray, ONE_HUNDRED_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}
			else if (elements == 4)
			{
				start = clock();
				int theArray[TWO_HUNDRED_FIFTY_THOUSAND];
				populateArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				quickSort2(theArray, 0, TWO_HUNDRED_FIFTY_THOUSAND);
				printArray(theArray, TWO_HUNDRED_FIFTY_THOUSAND);
				cout <<"Total CPU time used: " << (double) (clock() - start)/CLOCKS_PER_SEC << " seconds"<<endl;
			}

		}
		else if (menuChoice == 7)
		{
			done = true;
		}

	}

	return 0;
}


void populateTxtOne() //1 hundred
{
	ofstream txtOutput; 
	txtOutput.open("input1.txt");
	for (int i = 0; i < ONE_HUNDRED; i++)
	{
		txtOutput << rand() % 100<<endl;	
	}
	txtOutput.close();

}
void populateTxtTwo() //1 thousand
{
	ofstream txtOutput;
	txtOutput.open("input2.txt");
	for (int i = 0; i < ONE_THOUSAND; i++)
	{
		txtOutput << rand() % 100<<endl;	
	}
	txtOutput.close();

}
void populateTxtThree() //1 one hundred thousand
{
	ofstream txtOutput;
	txtOutput.open("input3.txt");
	for (int i = 0; i < ONE_HUNDRED_THOUSAND; i++)
	{
		txtOutput << rand() % 100<<endl;	
	}
	txtOutput.close();

}
void populateTxtFour() //two hundred fifty thousand
{
	ofstream txtOutput;
	txtOutput.open("input4.txt");
	for (int i = 0; i < TWO_HUNDRED_FIFTY_THOUSAND; i++)
	{
		txtOutput << rand() % 100<<endl;	
	}
	txtOutput.close();

}
template<class T>
void populateArray(T theArray[], int size)
{
	ifstream txtInput;
	if (size == ONE_HUNDRED)
	{
		txtInput.open("input1.txt");
		for (int i = 0; i < size; i++)
		{
			theArray[i] = rand() % 100;
		}
		txtInput.close();
	}
	else if (size == ONE_THOUSAND)
	{
		txtInput.open("input2.txt");
		for (int i = 0; i < size; i++)
		{
			theArray[i] = rand() % 100;
		}
		txtInput.close();

	}
	else if (size == ONE_HUNDRED_THOUSAND)
	{
		txtInput.open("input3.txt");
		for (int i = 0; i < size; i++)
		{
			theArray[i] = rand() % 100;
		}
		txtInput.close();

	}
	else if (size == TWO_HUNDRED_FIFTY_THOUSAND)
	{
		txtInput.open("input4.txt");
		for (int i = 0; i < size; i++)
		{
			theArray[i] = rand() % 100;
		}
		txtInput.close();

	}

}
template<class T>
void printArray(T theArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << theArray[i] << " ";
	}
	cout<<endl;
}
template<class T>
void quickSort(T theArray[], int first, int last)
{
	if(first < last)     // Create the partition: S1 | Pivot | S2
	{
		int pivotIndex = partition(theArray, first, last);
	// Sort subarrays S1 and S2
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}
}// end quickSort
template<class T>
int partition(T theArray[], int first, int last)
{
	// Choose pivot 
	int pivotIndex = last-1; 
	int pivot=theArray[pivotIndex];
	//cout<<" the pivot index and pivot "<< pivotIndex<<" "<< pivot<<endl;
	// Determine the regions S1 and S2
	int indexFromLeft = first ;
	int indexFromRight = last-2;
   
	bool done = false;
	while (!done)
	{
		// Locate first entry on left that is >= pivot
		while (theArray[indexFromLeft] < pivot)
		{
			indexFromLeft = indexFromLeft + 1;
      		}
		// Locate first entry on right that is <= pivot
		while (theArray[indexFromRight] > pivot)
		{
			indexFromRight = indexFromRight - 1;
		}      
		if (indexFromLeft < indexFromRight)
		{
			swapValues(theArray[indexFromLeft], theArray[indexFromRight]);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}
		else
		{
			done = true;
		}
	}// end while
	// Place pivot in proper position between S1 and S2, and mark its new location
	swapValues(theArray[pivotIndex], theArray[indexFromLeft]);
	pivotIndex = indexFromLeft;
	return pivotIndex;
}// end partition

template<class T>
void insertionSort(T a[], int size)
{
	for(int i=0; i<size-1;i++)
	{
		for(int j=i+1; j>0; j--)
		{
			if(a[j-1] > a[j])
			{
				swapValues(a[j], a[j-1]);
			}
		       else
			{
				break;
			}
		}
	}
}
template<class T>
void swapValues(T& x, T& y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;

}
template<class T>
void merge(T theArray[], int first, int mid, int last)
{
	int tempArray[last+1];  // Temporary array

	// Initialize the local indices to indicate the subarrays
	int first1 = first;            // Beginning of first subarray
	int last1 = mid;               // End of first subarray
	int first2 = mid + 1;          // Beginning of second subarray
	int last2 = last;              // End of second subarray

	// While both subarrays are not empty, copy the
	// smaller item into the temporary array
	int index = first1;            // Next available location in tempArray
	while ((first1 <= last1) && (first2 <= last2))
	{
	// At this point, tempArray[first..index-1] is in order
		if (theArray[first1] <= theArray[first2])
		{
			tempArray[index] = theArray[first1];
			first1++;
		}
		else
		{
			tempArray[index] = theArray[first2];
			first2++;
		}  // end if
		index++;
	}  // end while
   
	// Finish off the first subarray, if necessary
	while (first1 <= last1)
	{
		// At this point, tempArray[first..index-1] is in order
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}  // end while
   
	// Finish off the second subarray, if necessary
	while (first2 <= last2)
	{
		// At this point, tempArray[first..index-1] is in order
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}  // end for
   
	// Copy the result back into the original array
	for (index = first; index <= last; index++)
	{
		theArray[index] = tempArray[index];
	}
}  // end merge

template<class T>
void mergeSort(T theArray[], int first, int last)
{
	if (first < last)
	{
		// Sort each half
		int mid = first + (last - first) / 2; // Index of midpoint
      
		// Sort left half theArray[first..mid]
		mergeSort(theArray, first, mid);

		// Sort right half theArray[mid+1..last]
		mergeSort(theArray, mid + 1, last);

		// Merge the two halves
		merge(theArray, first, mid, last);
	}  // end if
}  // end mergeSort
template<class T>
void selectionSort(T arr[], int size)
{
	int indexofLargest;
	for(int i=0; i<size; i++)
	{
		indexofLargest = findIndexOfLargest(arr, size-i);  
		swapValues(arr[indexofLargest],arr[size-i-1]);
        }
}
template<class T>
int findIndexOfLargest(T a[], int s)
{
	int largest=a[0];
	int index=0;
	for(int i=1; i<s;i++)
	{
		if(a[i]>largest)
		{
			largest=a[i];
			index=i;
		}
	}
	return index;
}
template<class T>
void bubbleSort(T a[], int size)
{
	for(int i=0; i < size; i++)
	{
		for(int j=0; j < size-i-1; j++)
		{
			if( a[j]>a[j+1])
			{
				swapValues(a[j], a[j+1]);
			}
		}
	}
}
template<class T>
int findMidPivot(T theArray[], int first, int last)
{
	int midIndex = (first + last) / 2;
	return midIndex;
}
template<class T>
void quickSort2(T theArray[], int first, int last)
{
	if(first < last)     // Create the partition: S1 | Pivot | S2
	{
		int pivotIndex = findMidPivot(theArray, first, last);		
//		int pivotIndex = partition(theArray, first, last);
	// Sort subarrays S1 and S2
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}
}// end quickSort
template<class T>
int partition2(T theArray[], int first, int last)
{
	// Choose pivot 
	int pivotIndex = last-1; 
	int pivot=theArray[pivotIndex];
	//cout<<" the pivot index and pivot "<< pivotIndex<<" "<< pivot<<endl;
	// Determine the regions S1 and S2
	int indexFromLeft = first ;
	int indexFromRight = last-2;
   
	bool done = false;
	while (!done)
	{
		// Locate first entry on left that is >= pivot
		while (theArray[indexFromLeft] < pivot)
		{
			indexFromLeft = indexFromLeft + 1;
      		}
		// Locate first entry on right that is <= pivot
		while (theArray[indexFromRight] > pivot)
		{
			indexFromRight = indexFromRight - 1;
		}      
		if (indexFromLeft < indexFromRight)
		{
			swapValues(theArray[indexFromLeft], theArray[indexFromRight]);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}
		else
		{
			done = true;
		}
	}// end while
	// Place pivot in proper position between S1 and S2, and mark its new location
	swapValues(theArray[pivotIndex], theArray[indexFromLeft]);
	pivotIndex = indexFromLeft;
	return pivotIndex;
}// end partition


