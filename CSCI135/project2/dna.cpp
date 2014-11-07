/**********************************************************************
 Title:         : dna.cpp
 Author         : Krirk Pongsema
 Created on     : 11/26/2013
 Description    : implementation file for project #2
 Purpose        : function definitions
 Modification   : Revised version 3. 12/8/13 7:00pm
 **********************************************************************/

#include "dna.h"

//DNA Member Functions

DNAstrand::DNAstrand()
{

}

DNAstrand::DNAstrand(string input)
{
	nucl = input;
}

bool DNAstrand::checkDNA(string dnaTest)
{

	for (int i = 0; i < dnaTest.length(); i++)
	{
		if (dnaTest[i] != 'a' && dnaTest[i] != 'c' && dnaTest[i] != 'g' && dnaTest[i] != 't')
		{
			return false;
		}
	}
	return true;
}


string DNAstrand::getDNA()
{
	return nucl;
}

string DNAstrand::transcribe()
{
	string n;
	n = nucl;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == 't')
		{
			n[i] = 'u';
		}
	}
	return n;
}

//RNA Member Functions

RNAstrand::RNAstrand()
{

}

RNAstrand::RNAstrand(string r)
{
	strand = r;
}

string RNAstrand::getRNA()
{
	return strand;
}


//RCodon Member Functions

RCodon::RCodon()
{

}

RCodon::RCodon(string r)
{
	triplet = r;
}

string RCodon::getRC()
{
	return triplet;
}

void RCodon::translate()
{
//used https://scontent-b-iad.xx.fbcdn.net/hphotos-prn2/v/1503646_10151832983187058_1226472389_n.jpg?oh=9372b581868e0658d37680d6958850b6&oe=52A78F84 for codon translations
//not sure if i'm reading the chart correctly.
//no chart supplied to the class for codon translations

	ofstream outProt;
	outProt.open("krirk_proteins.txt", ios::app);
	if (triplet == "aug") // start codon
	{
		outProt <<endl;
		protein = "Met";
		outProt << protein << " ";
	}
	else if (triplet == "uaa" || triplet == "uag" || triplet == "uga") // stop codons
	{
		cout << endl;
	}
	else if (triplet == "uuu" || triplet == "uuc")
	{
		protein = "Phe";
		outProt << protein << " ";
	}
	else if (triplet == "uua" || triplet == "uug")
	{
		protein = "Leu";
		outProt << protein << " ";
	}
	else if (triplet == "cuu" || triplet == "cuc" || triplet == "cua" || triplet == "cug")
	{
		protein = "Leu";
		outProt << protein << " ";
	}
	else if (triplet == "auu" || triplet == "auc" || triplet == "aua")
	{
		protein = "lle";
		outProt << protein << " ";
	}
	else if (triplet == "guu" || triplet == "guc" || triplet == "gua" || triplet == "gug")
	{
		protein = "Val";
		outProt << protein << " ";
	}
	else if (triplet == "ucu" || triplet == "ucc" || triplet == "uca" || triplet == "ucg")
	{
		protein = "Ser";
		outProt << protein << " ";
	}
	else if (triplet == "ccu" || triplet == "ccc" || triplet == "cca" || triplet == "ccg")
	{
		protein = "Pro";
		outProt << protein << " ";
	}
	else if (triplet == "acu" || triplet == "acc" || triplet == "aca" || triplet == "acg" )
	{
		protein = "Thr";
		outProt << protein << " ";
	}
	else if (triplet == "gcu" || triplet == "gcc" || triplet == "gca" || triplet == "gcg")
	{
		protein = "Ala";
		outProt << protein << " ";
	}
	else if (triplet == "uau" || triplet == "uac")
	{
		protein = "Tyr";
		outProt << protein << " ";
	}

	else if (triplet == "cau" || triplet == "cac")
	{
		protein = "His";
		outProt << protein << " ";
	}
	else if (triplet == "caa" || triplet == "cag")
	{
		protein = "Gln";
		outProt << protein << " ";
	}
	else if (triplet == "aau" || triplet == "aac")
	{
		protein = "Asn";
		outProt << protein << " ";
	}
	else if (triplet == "aaa" || triplet == "aag")
	{
		protein = "Lys";
		outProt << protein << " ";
	}
	else if (triplet == "gau" || triplet == "gac")
	{
		protein = "Asp";
		outProt << protein << " ";
	}
	else if (triplet == "gaa" || triplet == "gag")
	{
		protein = "Glu";
		outProt << protein << " ";
	}
	else if (triplet == "ugu" || triplet == "ugc")
	{
		protein = "Cys";
		outProt << protein << " ";
	}
	else if (triplet == "ugg")
	{
		protein = "Trp";
		outProt << protein << " ";
	}
	else if (triplet == "cgu" || triplet == "cgc" || triplet == "cga" || triplet == "cgg")
	{
		protein = "Arg";
		outProt << protein << " ";
	}
	else if (triplet == "agu" || triplet == "agc")
	{
		protein = "Ser";
		outProt << protein << " ";
	}
	else if (triplet == "aga" || triplet == "agg")
	{
		protein = "Arg";
		outProt << protein << " ";
	}
	else if (triplet == "ggu" || triplet == "ggc" || triplet == "gca" || triplet == "ggg")
	{
		protein = "Gly";
		outProt << protein << " ";
	}
	outProt.close();



}



