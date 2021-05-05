// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #4
// Useful for sorting things with recursion. 


#include "BinarySearchTree.h"
#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <fstream>
BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	size = 0;
}
BinarySearchTree::~BinarySearchTree()
{
	cout << "\n BinarySearchTree Destructor is called. Tree DESTROYED This is essentially my clear() function" << endl;
	delete root;
}

void BinarySearchTree::clear(BinaryTreeNode* node)
{
	//The destuctor basically does this. Unsure why we need this. 
	//Post order, deletes each node of the tree. 
		if (node == NULL) 
			{
			return;
			}
		// else 
		// delete both subtrees 
		clear(node->left);
		clear(node->right);

		// delete the node 
		cout << "\n Deleting node: " << node->lastname;
		delete node;
		size--;
}

BinaryTreeNode* BinarySearchTree::insert(string emp, BinaryTreeNode* v)
{
	//So if the tree doesnt have any nodes, its empty. Create a new node as root.
	if(size == 0) {

		BinaryTreeNode* newRoot = new BinaryTreeNode(emp);
		root = newRoot;
		size++;
		return root;
	}
	//compare the string you want to store with the current nodes stored last name. 
	if (emp < v->lastname) 
	{
		//Left Logic
		//If there is an existing node. Use Recursion . Call the function again. 
		if (v->left != NULL) 
		{
			return insert(emp, v->left);
		}
		//Otherwise make a new node to the left of the current node its looking at. 
		else 
		{
			BinaryTreeNode* node = new BinaryTreeNode(emp);
			v->left = node;
			size++;
			return v->left;
		}
	} 
	else //Right Logic. Similar to logic above just with nodes to the right. 
	{
		if (v->right != NULL)
		{
			return insert(emp, v->right);
		}
		else
		{
			BinaryTreeNode* node = new BinaryTreeNode(emp);
			v->right = node;
			size++;
			return v->right;
		}
	}
	//output is a new node w in the subtree that stores the (Key, String)
	//BinaryTreeNode node = BinaryTreeNode(emp,search()*;

}

bool BinarySearchTree::search(string lastname, BinaryTreeNode* root)
{
	BinaryTreeNode* node = root;
	while (node != NULL) 
	{
		if (lastname < node->lastname) 
		{
			node = node->left;
		}
		else if (lastname > node->lastname) 
		{
			node = node->right;
		}
		else 
		{
			//Found item
			cout << lastname << " was found" << endl;
			return true;
		}
	}
	//Item is not in the BST tree.
	cout << lastname << " was not found" << endl;
	return false;
}
void BinarySearchTree::inorderPrint(BinaryTreeNode* root) {
	if (root != NULL) {
		inorderPrint(root->left);
		cout << root->lastname << " ";
		inorderPrint(root->right);
	}
}
BinaryTreeNode* BinarySearchTree::remove(string in, BinaryTreeNode* root)
{
	// base case
	if (root == NULL)
		return root;

	// left tree recursive searching
	if (in < root->lastname)
		root->left = remove(in, root->left);

	// right tree recursive searching
	else if (in > root->lastname)
		root->right = remove(in, root->right);

	// if the input last name is the same as the roots last name, proceed. 
	else {
		// node has no child
		if (root->left == NULL and root->right == NULL) 
			{
			return NULL;
			}
			// Left logic for node with only one child or no child
			else if (root->left == NULL) 
			{
			BinaryTreeNode* temp = root->right;
			free(root);
			return temp;
			}
			// Right logic node with only one child or no child
			else if (root->right == NULL) 
			{
			 BinaryTreeNode* temp = root->left;
			free(root);
			return temp;
			}
		// node with two children: Get the inorder successor
		BinaryTreeNode* temp = GetPredecessor(root->right);

		// Copy the inorder successor's content to this node
		root->lastname = temp->lastname;

		// Delete the inorder successor
		//cout << "\nDeleted: " << temp->lastname << endl;
		size--;
		root->right = remove(temp->lastname, root->right);
	}
	return root;

}
BinaryTreeNode* BinarySearchTree::GetPredecessor(BinaryTreeNode* node)
{
	BinaryTreeNode* current = node;

	// loop down BST to find the most left node. 
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

int BinarySearchTree::BSTsize()
{
	return size;
}

void BinarySearchTree::save(BinaryTreeNode* root, ofstream& out)
{
	//Essentially the same as inorderPrint but modified to write out to a file.
	string lname;
	if (root != NULL) {
		save(root->left, out);
		lname = root->lastname;
		out << lname << " ";
		save(root->right, out);
	}
}
BinaryTreeNode* BinarySearchTree::getRoot() const
{
	return root;
}
