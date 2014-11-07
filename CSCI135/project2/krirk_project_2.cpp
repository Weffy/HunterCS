/**********************************************************************
 Title:         : krirk_project_2.cpp
 Author         : Krirk Pongsema
 Created on     : 11/26/2013
 Description    : driver file for project #2
 Purpose        : main program
 Modification   : Revised version 3. 12/9/13 7:00pm
 **********************************************************************/

#include "dna.h"

int main()
{
//vars
	string dnaInput;
	string rnaInput;
	string rcInput;
	string rcInput2;
	bool checkTest;
	vector <DNAstrand> vecDNA;
	vector <RNAstrand> vecRNA;
	vector <RCodon> vecRC;
	DNAstrand check;
	ifstream inFile;
	int choice = 0;
	while (choice != 1 && choice != 2)
	{
		cout <<"clear data in protein file from previous run?"<<endl;
		cout <<"(1) Yes"<<endl;
		cout <<"(2) No"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			ofstream clear;
			clear.open("krirk_proteins.txt");
			clear.close();
		}
		else if (choice == 2)
		{
			break;
		}
	}
//gathers input
	inFile.open("krirk_dna.txt");

/* see lines 121 - 125 for explanation of commenting this out
	cout <<endl;
	cout <<"This program accesses file krirk_dna.txt,"<<endl;
	cout <<"it transcribes the DNA strands into RNA strands"<<endl;
	cout <<"and outputs them in file krirk_rna.txt."<<endl;
	cout <<"Then it translates these RNA strands into proteins"<<endl;
	cout <<"and keeps them in file krirk_proteins.txt"<<endl;
*/
//checks to see if string is valid
//if valid, keeps the string and stores in a vector

	while(!inFile.eof())
	{
		inFile >> dnaInput;
		checkTest = check.checkDNA(dnaInput);
		if (checkTest == true)
		{
			vecDNA.push_back(dnaInput);
		}
		if (checkTest == false)
		{
			cout << "invalid input."<<endl;
			cout << "quitting program."<<endl;
			exit(1);
		}
	}
	inFile.close();
/*
//testing to see if data is saved in vector
	cout << "DNA"<<endl;
	cout <<endl;
	for (int i = 0; i < vecDNA.size(); i++)
	{

		cout <<i<<": " << vecDNA[i].getDNA()<<endl;
	}
*/
	
//transcribe the DNA in the vector
	cout <<"Beginning transcription and translation."<<endl;
	for (int i = 0; i < vecDNA.size(); i++)
	{
		rnaInput = vecDNA[i].transcribe();
		vecRNA.push_back(rnaInput);		
		
	}
/*
//testing to see if data is saved in vector
	cout << "RNA"<<endl;
	cout <<endl;
	for (int i = 0; i < vecRNA.size(); i++)
	{

		cout <<i<<": " << vecRNA[i].getRNA()<<endl;
	}
*/

//output to txt file
	ofstream outFile;
	outFile.open("krirk_rna.txt");
	for (int i = 0; i < vecRNA.size(); i++)
	{

		outFile << vecRNA[i].getRNA()<<endl;
	}	

//RNA into triplets
//save into a vector of RCodon objects

	for (int i = 0; i < vecRNA.size(); i++)
	{

		rcInput = vecRNA[i].getRNA();
		for (int j=0; j<99 ; j+=3)
		{
//the large amounts of blank space in the output comes from this line below
//if you comment it out, the output no longer has all the empty space
//i am not sure why this is the case with the member function substr
//as a work-around, i will move the couts above down to the bottom so it
//appears as one whole paragraph
			rcInput2 = rcInput.substr(j, 3); 
			vecRC.push_back(rcInput2);
		}

	}

/*
//testing to see if data is saved in vector
	cout << "RCodon"<<endl;
	cout <<endl;
	for (int i = 0; i < vecRC.size(); i++)
	{

		cout <<i<<": " << vecRC[i].getRC()<<endl;
	}
*/
//translating codons into proteins
//output is inside of member function translate
	for (int i = 0;i < vecRC.size(); i++)
	{
		vecRC[i].translate();
	}

	cout <<endl;
	cout <<"This program accesses file krirk_dna.txt,"<<endl;
	cout <<"it transcribes the DNA strands into RNA strands"<<endl;
	cout <<"and outputs them in file krirk_rna.txt."<<endl;
	cout <<"Then it translates these RNA strands into proteins"<<endl;
	cout <<"and keeps them in file krirk_proteins.txt"<<endl;
	cout <<"The process has ended."<<endl;
	return 0;
}
