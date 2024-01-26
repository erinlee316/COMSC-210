//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 1
//        Date: 8/24/2023
//     Problem: Make a grocery list that the user can edit, which they can display at any time.
// Description: Program uses singularly linked list, and the user can add, delete, and display nodes in
//              the list. Program will determine if node already exists and will not allow duplicate nodes.
//************************************************************************************************************

#include <iostream>
using namespace std;

// declare structure variable 
struct node
{
  string item;
  node* next;
};

// function prototypes
void addNode(node* &);
void deleteNode(node* &);
void displayNode(node*);
bool duplicateNode(node*, int);

int main()
{
  // define and initialize variables
  int option = 0;

  // create null pointer
  node *head = NULL;

  // ask for user input
  cout << "(1 - add item, 2 - delete item, 3 - display item(s), 4 - exit)" << endl;
  cout << "Choose an option: ";
  cin >> option;

  // keeps looping until user inputs 4
  while (option != 4)
  {
    // choices available depending on user's input
    switch(option)
    {
      case 1:
        addNode(head);
        break;

      case 2:
        deleteNode(head);
        break;

      case 3: 
        displayNode(head);
        break;

      default:
        cout << "Invalid input.\n" << endl;
        break;
      }

    // asks for user input again
    cout << "(1 - add item, 2 - delete item, 3 - display item(s), 4 - exit)" << endl;
    cout << "Choose an option: ";
    cin >> option;
  }

  cout << "Program ending...\n" << endl;
  return 0;
}


// function checks if any nodes have a duplicate item as user input
// function will return true if a duplicate item is found, or else, returns false
bool duplicateNode(node *head, string userInput)
{
  // declare and initialize variable
  bool duplicate = false;

  // make current pointer and initialize it with head item
  node* current = head;

  // keeps looping to check all nodes in list
  while (current != NULL)
  {
    // bool turns true if user input matches node in list
    if (current->item == userInput)
      duplicate = true;

    // assigns current pointer to next node value
    current = current->next;
  }

  // returns true or false
  return duplicate;
}


// function allows user to add item/create new node into the list.
// function will call duplicateNode() to not allow duplicate items to be added
void addNode(node *&head)
{
  // declare variable
  string userInput;

  // create pointers of node type
  node *newNode;
  node *current;

  // ask for user input
  cout << "Enter item you want to add (no duplicates): ";
  cin.ignore();
  getline(cin, userInput);

  // function call checks to see if there is duplicate item in program
  if (duplicateNode(head, userInput))
    cout << "Duplicate item found. Cannot add to list.\n" << endl;

  // statement if no duplicate item is found in program
  else
  {
    // prepare new node to be added into list
    // allocate, store, and point new data of newNode to null 
    newNode = new node;
    newNode->item = userInput;
    newNode->next = NULL;

    // sets newNode as first item of list if program finds that there are no oher nodes 
    if (head == NULL)
      head = newNode;

    // list is not empty, so program will add user input at the end of list
    else
    {
      current = head;

      // keeps looping until node reaches null
      while (current->next != NULL)
        current = current->next;

      // statement adds user input at end of list when current reaches null
      current->next = newNode; 
    }

    cout << endl;
  }
}


// function will delete item in list that user wants deleted.
// but if user input cannot be found in list, no item will be deleted.
void deleteNode(node *&head)
{
  // declare variable
  string userInput;

  // create pointers of type node for linked list
  node *current;
  node *previous;

  // if head is null, program cannot delete any items
  if (head == NULL)
    cout << "List is empty. Cannot delete any items." << endl;

  // list contains nodes, so program will search for item
  else
  { 
    // ask for user input
    cout << "Enter item you want deleted: ";
    cin.ignore();
    getline(cin, userInput);

    // declare pointers
      current = head;
      previous = NULL;

    // keeps looping as long as current node doesn't reach end of list and is not equivalent to user input
    while (current != NULL && current->item != userInput)
    {
      previous = current;
      current = current->next;
    }

    // statement cannot find node after traversing through list
    if (current == NULL)
      cout << "Item you want to delete cannot be found." << endl;
        
    // statement shows that previous node is the only string in list, so deletes current node
    else if (previous == NULL)
    {
      head = head->next;
      delete current;
    }

    // statement shows that user input is found in list, so deletes current node
    else 
    {
      previous->next = current->next;
      delete current;
    }
  }

  cout << endl;
}


// function will display contents in the linked list
void displayNode(node *head)
{
  // statement if there are no nodes in list
  if (head == NULL)
    cout << "List is empty.\n";

  // statement if there are nodes in list
  else
  {
    cout << "\nGrocery list" << endl;
    cout << "------------" << endl;

    // loop displays contents of list starting from head
    while (head != NULL)
    {
      cout << head->item << endl;
      head = head->next;
    }
  }

  cout << endl;
}