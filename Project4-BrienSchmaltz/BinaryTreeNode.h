// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #4

#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class BinaryTreeNode{
protected:
	//Unsure about friend class come back to
	friend class BinarySearchTree;
	string lastname ;
	BinaryTreeNode * parent;
	//Keys stored in the left subtree of v are less than or equal to K. Each internal node(v) of a tree stores an entry (k,x)
	BinaryTreeNode * left;
	//Keys stored in the right stubtree of v are greater than or equal to K.
	BinaryTreeNode * right;
	
	BinaryTreeNode(string Lname, BinaryTreeNode* parentptr = NULL, BinaryTreeNode* rightptr = NULL, BinaryTreeNode* leftptr = NULL);

	~BinaryTreeNode();
};
#endif
