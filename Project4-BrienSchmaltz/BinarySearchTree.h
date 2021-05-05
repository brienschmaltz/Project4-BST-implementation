// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #4

#ifndef _BinarySearchTree_
#define _BinarySearchTree_

#include <cstdlib>
#include "BinaryTreeNode.h"

using namespace std;
//template <typename K, typename V>

class BinarySearchTree {

	//public:					// public types
		//typedef K Key;		// key type
		//typedef V Value;	// value type
	public:
		BinarySearchTree();	//constructor
		~BinarySearchTree();	//destructor
		void clear(BinaryTreeNode* node); //Delete all the nodes in the BST using postorder tree traversal
		BinaryTreeNode* insert(string emp, BinaryTreeNode* v);
		bool search(string lastname, BinaryTreeNode* v);
		BinaryTreeNode* GetPredecessor(BinaryTreeNode* node);
		BinaryTreeNode* remove(string lastname, BinaryTreeNode* v);
		void inorderPrint(BinaryTreeNode* root);
		int BSTsize();
		void save(BinaryTreeNode* root, ofstream& out);
		BinaryTreeNode* getRoot() const;
	private:
		BinaryTreeNode * root;
		int size;
};


#endif
 
