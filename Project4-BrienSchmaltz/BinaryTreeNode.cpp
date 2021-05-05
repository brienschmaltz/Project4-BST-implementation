// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #4
#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(string Lname, BinaryTreeNode* parentptr, BinaryTreeNode* rightptr, BinaryTreeNode* leftptr)
{
	lastname = Lname;
	//parent = parentptr;
	//left = leftptr;
	//right = rightptr;
}
BinaryTreeNode::~BinaryTreeNode()
{
	cout << "\n Deleting: " << lastname << endl;
	delete left;
	delete right;
	
}
