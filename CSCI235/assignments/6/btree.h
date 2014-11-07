/************************************************
 Title:         : btree.h
 Author         : Krirk Pongsema
 Created on     : 5/11/2014
 Description    : header file containing class
		  and node information.
 Change log	:
 5/11/14	: need to fix the tree traversal
		  algorithm.  
 5/12/14	: insert function not working
		  correctly.  need to find bug
 5/13/14	: class is finally working!
 5/14/14	: v2, adding strings for type
		  notcing a problem.  I may need
		  to create the tree in reverse
		  order
 5/17/14	: scrapped previous class, trying
		  to redo to create leaves first
		  having issues getting access to
		  private variable
 5/18/14	: put in a accessor to get access
		  to the different struct variables
		  couldn't get iterator working
		  had issues getting a list working
		  when building the tree from the
		  leaves up
***************************************************/

#ifndef BTREE_H 
#define BTREE_H
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Node
{
	double data;
	string type;
	Node* left;
	Node* right;
};

class Tree
{
	public:
		Tree();
		~Tree();
		void insert(double data, string name);
		void insert(Node* l, Node* r);
//		void print();
		Node* getRoot();
		void postOrder();
	        void destroy_tree();
	private:
		Node* root;
		void postOrder(Node* n);
		void destroy_tree(Node* a_root);

	
};

int mp(list<Tree*> a_list);


#endif
