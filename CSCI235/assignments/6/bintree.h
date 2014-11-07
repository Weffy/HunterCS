/**********************************************
 Title:         : bintree.h
 Author         : Krirk Pongsema
 Created on     : 5/11/2014
 Description    : header file containing class
		  and node information.
***********************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>

using namespace std;

struct BTNode
{
	int data;
	BTNode* left;
	BTNode* right;
};

class BTree
{
	public:
		BTree();
		~BTree();

		void insert(int stuff);
		BTNode* search(int stuff);
		void destroy_tree();
		void inOrder();
		void remove(int stuff, BTNode* child);
	private:
		BTNode* root;

		void insert(int stuff, BTNode* child);
		BTNode* search(int stuff, BTNode* child);
		void destroy_tree(BTNode* child);
		void inOrder(BTNode* child);
		void remove(int stuff, BTNode* child);

};


#endif
