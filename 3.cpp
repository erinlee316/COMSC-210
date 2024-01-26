//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 3
//        Date: 10/4/2023
// Description: Program will implement a binary tree that uses preorder traversal to display a given set of numbers.
//************************************************************************************************************

#include <iostream>
using namespace std;


// define structure variable
// declare new binary search tree node
struct BSTnode
{
  int number;
  BSTnode *left;
  BSTnode *right;
};


// define function prototypes
BSTnode* getNewNode(int);
BSTnode* insertNode(BSTnode*, int);
void preorder(BSTnode*);


int main()
{

  // creates an empty binary tree
  BSTnode* root = NULL;

  // function call inserts numbers/nodes into binary tree
  // passes address of root to create new node
  root = insertNode(root, 8);
  root = insertNode(root, 4);
  root = insertNode(root, 2);
  root = insertNode(root, 5);
  root = insertNode(root, 12);
  root = insertNode(root, 29);

  // display inserted numbers from root, left subtree, then right subtree
  cout << "BST using preorder traversal: ";
  
  // function call to perform preorder traversal
  preorder(root);

  return 0;
}


// function creates new BST node
BSTnode* getNewNode(int value)
{
  // node gets allocated to dynamic memory and assigned to new value
  BSTnode *newNode = new BSTnode();
  newNode->number = value;

  // declare the new node's left and right child as null
  newNode->left = NULL;
  newNode->right = NULL;

  // returns new address of node
  return newNode;
}


// function will insert new nodes to BST in correct position
BSTnode* insertNode(BSTnode* root, int value)
{
  // checks if tree is empty
  if (root == NULL)
  {
      // tree will assign value as root of tree
      root = getNewNode(value);
      return root;
  }

  // checks if node wanting to be inserted is less than or equal to root node
  // will insert node into left side of tree if satisfied
  else if (value <= root->number)
    root->left = insertNode(root->left, value);

  // node wanting to be inserted is greater than root node
  // will insert node into right side of tree
  else
    root->right = insertNode(root->right, value);

  // return root pointer
  return root;
}


// perform preorder traversal of BST using recursives
// visits each node in tree and prints out the binary tree in preorder
void preorder(BSTnode* root)
{
  // prints node values if tree is not empty
  if (root != NULL)
  {
    cout << root->number << " ";

    // traverse the left subtree and right subtree recursively
    preorder(root->left);
    preorder(root->right);
  }
}

