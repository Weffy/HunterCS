/************************************************
 Title:         : qubi.cpp
 Author         : Krirk Pongsema
 Created on     : 5/11/2014
 Description    : driver program for assignment 6
*************************************************/

#include "btree.h"

int main()
{

	list<Tree*> t1;
/*******************
input of information
*******************/
	Tree* aTree = new Tree;
	aTree->insert(9.0, "Human");
	t1.push_back(aTree);

	aTree = new Tree;
	aTree->insert(11.0, "Ape");
	t1.push_back(aTree);

	aTree = new Tree;
	aTree->insert(14.0, "Monkey");
	t1.push_back(aTree);

	aTree = new Tree;
	aTree->insert(50.0, "Tiger");
	t1.push_back(aTree);

	aTree = new Tree;
	aTree->insert(55.0, "Lion");
	t1.push_back(aTree);

	aTree = new Tree;
	aTree->insert(76.0, "Elephant");
	t1.push_back(aTree);

	int midpoint;
	midpoint = mp(t1);
	Tree* leftArr[midpoint];
	Tree* rightArr[midpoint];
/*****************************************
midpoint will allow me to split the 
list into 2 separate parts
that will represent each side of the tree
******************************************/

	for (int i = 0; i < midpoint; i++)
	{
		Tree* temp;
		temp = t1.front();
		leftArr[i]=temp;
		t1.pop_front();		
	}
	for (int i = 0; i < midpoint; i++)
	{
		Tree* temp;
		temp = t1.front();
		rightArr[i]=temp;
		t1.pop_front();		
	}
/******************************
put the data back into a list
no real reason other than I
wanted to work more with lists
*******************************/
	list<Tree*>tRight;
	list<Tree*>tLeft;
	for (int i = 0; i < midpoint; i++)
	{
		Tree* temp;
		temp = leftArr[i];
		tLeft.push_back(temp);
	}
	for (int i = 0; i < midpoint; i++)
	{
		Tree* temp;
		temp = rightArr[i];
		tRight.push_back(temp);
	}
///////////////////////////////////////////////////////

//	cout <<"left tree"<<endl;

/************************************
left side of the tree
I tried to get this into a loop
but I kept getting errors
I also ran out of time.
wish I could've done a better job here
*************************************/


	aTree = new Tree;
	Node* tempLeft;
	tempLeft = tLeft.front()->getRoot();
	tLeft.pop_front();

	Node* tempRight;
	tempRight = tLeft.front()->getRoot();
	tLeft.pop_front();

	aTree = new Tree;
	aTree->insert(tempLeft, tempRight);
//	cout <<aTree->getRoot()<<endl;
	tLeft.push_front(aTree);

	aTree = new Tree;
	tempLeft;
	tempLeft = tLeft.front()->getRoot();
	tLeft.pop_front();

	tempRight;
	tempRight = tLeft.front()->getRoot();
	tLeft.pop_front();

	aTree = new Tree;
	aTree->insert(tempLeft, tempRight);
//	cout <<aTree->getRoot()<<endl;
	tLeft.push_front(aTree);
/////////////////////////////////////////////////////////

//	cout <<"right tree"<<endl;
/*********************
right side of the tree
*********************/
	aTree = new Tree;
	tempLeft;
	tempLeft = tRight.front()->getRoot();
	tRight.pop_front();

	tempRight;
	tempRight = tRight.front()->getRoot();
	tRight.pop_front();

	aTree = new Tree;
	aTree->insert(tempLeft, tempRight);
//	cout <<aTree->getRoot()<<endl;
	tRight.push_front(aTree);

	aTree = new Tree;
	tempLeft;
	tempLeft = tRight.front()->getRoot();
	tRight.pop_front();

	tempRight;
	tempRight = tRight.front()->getRoot();
	tRight.pop_front();

	aTree = new Tree;
	aTree->insert(tempLeft, tempRight);
//	cout <<aTree->getRoot()<<endl;
	tRight.push_front(aTree);

////////////////////////////////////////////////////////////////////

//	cout <<"Full Tree"<<endl;
/*******************
combining both trees
*******************/

	aTree = new Tree;
	tempLeft = tLeft.front()->getRoot();
	tempRight = tRight.front()->getRoot();
	aTree->insert(tempLeft, tempRight);
	
	aTree->postOrder();
	cout<<endl;
	aTree->destroy_tree();
	
	return 0;
}
