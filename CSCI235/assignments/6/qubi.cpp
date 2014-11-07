/**********************************************
 Title:         : qubi.cpp
 Author         : Krirk Pongsema
 Created on     : 5/11/2014
 Description    : driver for assignment 6
***********************************************/

#include "bintree.h"

int main()
{
	BTree t1;
	t1.insert(20);
	t1.insert(25);
	t1.insert(30);	
	t1.inOrder();
	cout<<endl;
	return 0;
}
