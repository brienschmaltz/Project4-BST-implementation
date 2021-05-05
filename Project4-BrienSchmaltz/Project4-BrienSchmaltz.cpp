// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #4

#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <fstream>

#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{   
    BinarySearchTree bst;
    string name, input;
    char choice;

    ifstream in;
    in.open("all.last.txt");
    int n = 0;
    // (1) Testing I/O, print. If you want to test more just change the function 
    while (n < 20 && getline(in, input))
    {
        cout << input << endl;
        bst.insert(input, bst.getRoot());
        n++;

    }

    // (1) Testing Print
    cout << "\nTesting inorderPrint: \n" << endl;
    bst.inorderPrint(bst.getRoot());

    // (1) and (5) Testing Save (basically print but slightly dif) (inorder)
    cout << "\n\nTesting Save: Check file called 'Test.txt' \n" << endl;
    ofstream o;
    o.open("Test.txt");
    bst.save(bst.getRoot(), o);

    // (2) Testing User Input
    string uinput;
    cout << "\nEnter in a last name you would like to add to the BST: \n" << endl;
    cin >> uinput;
    bst.inorderPrint(bst.getRoot());
    cout << "\n------------------- \n" << endl;
    //Insert
    bst.insert(uinput, bst.getRoot());
    //Print again. 
    bst.inorderPrint(bst.getRoot());
    cout << "\n------------------- \n" << endl;
    //
    // (3) Delete a Record user input
    cout << "\nEnter in a last name you would like to delete from the BST: (Easier to read if you just delete what you added earlier, or delete ANDERSON or WILSON) \n" << endl;
    string rinput;
    cin >> rinput;
    bst.remove(rinput, bst.getRoot());
    bst.inorderPrint(bst.getRoot());
    cout << "\n------------------- \n" << endl;

    //cout << "Current BST: Preorder" << endl;
    // (4) Testing search. 
    cout << "Searching for a Node named WILSON " << endl;
    bst.search("WILSON", bst.getRoot());
    cout << "Searching for a Node named CHARLES " << endl;
    bst.search("CHARLES", bst.getRoot());
    cout << "Searching for a Node named: (What you added earlier) " << uinput << endl;
    bst.search(uinput, bst.getRoot());
    
    
    //Other functions
    //Instructions aren't very clear. Testing clear() 
    cout << "\nTesting size function. Size is: " << bst.BSTsize() << endl;
    cout << "\nTesting clear. Instructions were not clear. Destructor deletes the pointers and the contents of each node up until the root. It does so below. I wrote a clear function regardless that could be used as well. (if you got rid of the destructor)" << endl;

}
