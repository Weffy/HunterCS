/************************************************
 Title:         : btree.cpp
 Author         : Krirk Pongsema
 Created on     : 5/11/2014
 Description    : implementation of class/struct
		  functions
**************************************************/

#include "btree.h"
/***********************
constructor / destructor
***********************/
Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	destroy_tree(root);
}
/*************************
methods to delete the tree
to free up memory
*************************/

void Tree::destroy_tree()
{
	destroy_tree(root);
}
void Tree::destroy_tree(Node* a_root)
{
	if(a_root!=NULL)
	{
		destroy_tree(a_root->left);
		destroy_tree(a_root->right);
		delete a_root;
	}
}
/******************************************************
I was having issues getting access to the private data.
I am sure there is a better way to accomplish this
but I ran out of time
******************************************************/
Node* Tree::getRoot()
{
	return root;
}
/*
two insert functions for two different scenarios
the first was for creating the initial nodes
the 2nd allowed me to create the parent nodes for 
the leaves we had to make first.
*/
void Tree::insert(double stuff, string name)
{
	root = new Node;
	root->data = stuff;
	root->type = name;
	root->left = NULL;
	root->right = NULL;

}
void Tree::insert(Node* l, Node* r)
{
	root = new Node;
	double leftNode;
	double rightNode;
	leftNode = l->data;
	rightNode = r->data;
	root->data = (leftNode + rightNode) / 2;
	root->type = "";
//	cout <<root->data<<endl;
	root->left = l;
	root->right = r;
	
	
}

/*void Tree::print()
{
	cout <<"data "<<root->data<<endl;
	cout <<"left data "<<root->left->data;
	cout <<"right data "<<root->right->data;
	cout <<endl;
}
*/
/************************************************
determines the Median number of items so I can 
split the list up into two separate sides which
will represent the different sides of the binary
tree
*************************************************/

int mp(list<Tree*> a_list)
{
	int size = a_list.size();
	return size/2;
}
void Tree::postOrder()
{
	postOrder(root);
}
void Tree::postOrder(Node* n)
{

	if (n != NULL)
	{
		cout<<"(";
		postOrder(n->left);
		postOrder(n->right);
		if (n->type == "")
		{
			cout <<")";
		}
		else
		{
			cout << n->type;
		}
		cout<<")";
	}

}




