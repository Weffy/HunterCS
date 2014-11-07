/**********************************************
 Title:         : bintree.cpp
 Author         : Krirk Pongsema
 Created on     : 5/11/2014
 Description    : Implementation of bintree
		  class and nodes.
***********************************************/

#include "bintree.h"

/***************************
constructor & deconstructors
***************************/
BTree::BTree()
{
	root = NULL;
}

BTree::~BTree()
{
	destroy_tree();
}

/***************
public functions
***************/

void BTree::insert(int stuff)
{
	if (root != NULL)
	{
		insert(stuff, root);
	}
	else
	{
		root = new BTNode;
		root->data = stuff;
		root->left = NULL;
		root->right = NULL;
	}
}

BTNode* BTree::search(int stuff)
{
	return search(stuff, root);
}

void BTree::destroy_tree()
{
	destroy_tree(root);
}
/*
void BSTree::remove(int stuff)
{
	remove(stuff, root);
}
*/

/**********************
tree traversal function
**********************/

void BTree::inOrder()
{
	inOrder(root);
}



/****************
private functions
****************/

void BTree::insert(int stuff, BTNode* child)
{
	if (stuff < child->data)
	{
		if (child->left != NULL)
		{
			insert(stuff, child->left);
		}
		else
		{
			child->left = new BTNode;
			child->left->data = stuff;
			child->left->left = NULL; 
			child->left->right = NULL;
		}
	}
	else if (stuff > child->data)
	{
		if (child->right != NULL)
		{
			insert(stuff, child->right);
		}
		else
		{
			child->right = new BTNode;
			child->right->data = stuff;
			child->right->left = NULL; 
			child->right->right = NULL;			
		}
	} 
}

BTNode* BTree::search(int stuff, BTNode* child)
{
	if (child != NULL)
	{
		if (stuff == child->data)
		{
			return child;
		}
		if (stuff < child->data)
		{
			return search(stuff, child->left);
		}
		else if (stuff > child->data)
		{
			return search(stuff, child->right);
		}
		else
		{
			return NULL;
		}
	}

}

void BTree::destroy_tree(BTNode* child)
{
	if(child != NULL)
	{
		destroy_tree(child->left);
		destroy_tree(child->right);
		delete child;
	}
}

void BTree::inOrder(BTNode* child)
{
	if (child!=NULL)
	{
		inOrder(child->left);
		cout<<child->data<<" ";
		inOrder(child->right);
	}
}
/*
void BSTree::remove(int stuff, BTNode* child)
{
	if(child == NULL)
	{
		return;
	}
	if(stuff < child->data)
	{
		remove(stuff, child->left);
	}
	else if(stuff >child->data)
	{
		remove(stuff, child->right);
	}
	else if(stuff == child->data)
	{
		if(child->left != NULL && child->right != NULL)
		{
			child->data= findMin(child->right)->data;
			cout<<"the item is "<<child->data<<endl;
			remove(child->data,child->right);
		}
		else
		{
			BTNode* temp = child;
			if(child->left != NULL)
			{
				child = child->left;
			}
			else
			{ 
				child = child->right;
			}
			delete temp;
		}
	}
}
*/
