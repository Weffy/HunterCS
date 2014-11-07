/**********************************************************************
 Title:         : dna.h
 Author         : Krirk Pongsema
 Created on     : 11/26/2013
 Description    : header file for project #2
 Purpose        : class definition
 Modification   : Revised version 3. 12/8/13 7:00pm
 **********************************************************************/
#ifndef DNA_H
#define DNA_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class DNAstrand
{
	public:
		DNAstrand();
		DNAstrand(string input);
		string getDNA();
		bool checkDNA(string dnaTest);
		string transcribe();
		
	private:
		string nucl;
};

class RNAstrand
{
	public:
		RNAstrand();
		RNAstrand(string r);
		string getRNA();

	private:
		string strand;
};

class RCodon
{
	public:
		RCodon();
		RCodon(string r);
		string getRC();
		void translate();
		
	private:
		string triplet;
		string protein;
};

#endif


