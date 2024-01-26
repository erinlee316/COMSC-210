//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Semester Project
//        Date: 11/08/2023
//     Problem: You work at as a reservation agent for a restaurant and you enter reservation information
//              made over the phone. You must enter the person's name, phone number, date of reservation, 
//              and time at which they would like to dine in.
// Description: Program uses linked list and merge sort to mimic a reservation system for the restaurant.
//              You can add, delete, edit, and display reservations. The program will sort based on date 
//              from ascending order. If the date is the same, program will sort based on time at which the 
//              guest is said to arrive.
//************************************************************************************************************


#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;


// declare structure variables
struct Reservation
{
  string name;
  string phoneNumber;
  string date;
  string time;
};

struct Node
{
  Reservation reservation;
  Node *next;
};


// function protoypes
Node *mergeSort(Node *);
Node *merge(Node *, Node *);
void split(Node *, Node **, Node **);
void userOptions(int&, Node *&);
void addReservation(Node *&, const Reservation &);
void deleteReservation(Node *&, const string &);
void modifyReservation(Node *&, const string &);
void displayReservations(Node *);


int main()
{
  // declare and initialize variables
  int choice = 0;
  Node *head = nullptr;

  // display to user
  cout << "Al Limone - Reservation System\n" << endl;
  cout << "1 - Add reservation, 2 - Delete reservation, 3 - Modify reservation, 4 - Display reservations, 5 - Exit" << endl;

  // get user input
  cout << "Enter your choice: ";
  cin >> choice;
  cout << endl;

  // function call
  userOptions(choice, head);

  // delete node from linked list
  while (head != nullptr)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  // program ending
  cout << "Program ending..." << endl;
  return 0;
}


// function acts as menu to add, delete, modify, and display nodes in linked list
void userOptions(int &choice, Node *&head)
{
  // keeps looping until user inputs (1-5)
  while (choice != 5)
  {
    switch (choice)
    {
      // option to add reservation
      case 1:
      {
        // declare struct variable
        Reservation reservation;

        // get info for reservation
        cout << "Enter information for reservation" << endl;
        cout << "Name: ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, reservation.name);
        cout << "Phone: ";
        getline(cin, reservation.phoneNumber);
        cout << "Date (mm/dd/yyyy): ";
        getline(cin, reservation.date);
        cout << "Time (hh:mm): ";
        getline(cin, reservation.time);

        // function call to add reservation to linked list
        addReservation(head, reservation);
        cout << "Reservation successfully added.\n" << endl;
        break;
      }

      // option to delete reservation
      case 2:
      {
        // declare variable
        string nameToDelete;

        // get user input
        cout << "Enter the name of reservation to delete: ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, nameToDelete);

        // function call to delete reservation and info from linked list
        deleteReservation(head, nameToDelete);
        break;
      }

      // option to modify reservation
      case 3:
      {
        // declare variable
        string nameToModify;

        // get user input
        cout << "Enter the name of reservation to modify: ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, nameToModify);

        // function call to modify reservation and change nodes in linked list
        modifyReservation(head, nameToModify);
        break;
      }

      // option to display reservations
      case 4:
      {
        // function call to perform merge sort of all data
        // function call to then display all reservations
        head = mergeSort(head);
        displayReservations(head);
        break;
      }

      // user input is not (1-5)
      default:
        cout << "Invalid input. Try again.\n" << endl;
    }

    // display and get user input
    cout << "1 - Add Reservation, 2 - Delete Reservation, 3 - Modify Reservation, 4 - Display Reservations, 5 - Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
  }
}


// function allows user to add new reservation to a linked list
void addReservation(Node *&head, const Reservation &newReservation)
{
  // declare and initialize pointer
  Node *newNode = new Node;

  // prepare new node to be added into list
  // allocate, store, and point new data to null
  newNode->reservation = newReservation;
  newNode->next = nullptr;

  // sets newNode as first item of list if program finds that there are no oher nodes 
  if (head == nullptr)
    head = newNode;

  // list is not empty, so program will add user input at the end of list
  else
  {
    Node *current = head;

    // keeps looping until node reaches null
    while (current->next != nullptr)
      current = current->next;

    // statement adds user input at end of list when current reaches null
    current->next = newNode;
  }
}


// function will delete reservation from linked list
// no item will be deleted if reservation is not found in list
void deleteReservation(Node *&head, const string &nameToDelete)
{
  // check if list is empty
  if (head == nullptr)
  {
    cout << "Reservation list is empty. Cannot delete.\n" << endl;
    return;
  }

  // declare and initialize pointers
  Node *current = head;
  Node *prev = nullptr;

  // traverse list and find reservation needed to be deleted
  while (current != nullptr && current->reservation.name != nameToDelete)
  {
    prev = current;
    current = current->next;
  }

  // cannot find node after traversing through list
  if (current == nullptr)
  {
    cout << "Reservation not found. Cannot delete.\n" << endl;
    return;
  }

  // previous node is the only node in list
  else if (prev == nullptr)
    head = head->next;

  // reservation is found in list
  else
    prev->next = current->next;

  // delete current node
  delete current;
  cout << "Reservation successfully deleted.\n" << endl;
}


// function will modify reservation information in linked list
void modifyReservation(Node *&head, const string &nameToModify)
{
  // check if list is empty
  if (head == nullptr)
  {
    cout << "Reservation list is empty. Cannot modify.\n" << endl;
    return;
  }

  // declare and initialize pointer
  Node *current = head;

  // traverses the list to find contact needed to modify
  while (current != nullptr && current->reservation.name != nameToModify)
    current = current->next;

  // cannot find node after traversing through list
  if (current == nullptr)
  {
    cout << "Reservation not found. Cannot modify.\n" << endl;
    return;
  }

  // node is found, so get user input for reservation again
  else
  {
  cout << "Enter information for reservation" << endl;
  cout << "Name: ";
  getline(cin, current->reservation.name);
  cout << "Phone: ";
  getline(cin, current->reservation.phoneNumber);
  cout << "Date (mm/dd/yyyy): ";
  getline(cin, current->reservation.date);
  cout << "Time (hh:mm): ";
  getline(cin, current->reservation.time);

  cout << "Reservation successfully modified\n" << endl;
  }
}


// function will display reservation information in linked list
void displayReservations(Node *head)
{
  // check if list is empty
  if (head == nullptr)
  {
    cout << "Reservation list is empty. Cannot display.\n" << endl;
    return;
  }

  // display info
  cout << "\nReservations at Al Limone\n" << endl;

  // keeps looping through linked list until head node is null
  while (head != nullptr)
  {
    // display info for each reservation
    cout << "Date: " << left << setw(15) << head->reservation.date
         << "Time: " << left << setw(10) << head->reservation.time
         << "Name: " << left << setw(20) << head->reservation.name
         << "Phone: " << left << setw(15) << head->reservation.phoneNumber << endl;

    // move to next node 
    head = head->next;
  }

  cout << endl;
}


// function will perform merge sort on linked list
Node *mergeSort(Node *source)
{
  // check if list in empty or has only one node
  // return if it is already sorted
  if (source == nullptr || source->next == nullptr)
    return source;

  // declare and initialize pointers
  Node *head = source;
  Node *front = nullptr;
  Node *back = nullptr;

  // split the list into two halves
  split(head, &front, &back);

  // recursively sort the two halves
  front = mergeSort(front);
  back = mergeSort(back);

  // after sorting, merge the sorted halves back together
  source = merge(front, back);

  // return sorted list
  return source;
}


// function will merge two sorted lists
Node *merge(Node *left, Node *right)
{
  // declare and initialize pointer
  Node *merging = nullptr;

  // check if one of the lists are empty
  // checks left list first
  if (left == nullptr)
    return right;

  // checks right list since left list is not empty
  else if (right == nullptr)
    return left;

  // neither of the lists are empty
  // checks if the date of the left list is smaller than right list
  if (left->reservation.date < right->reservation.date)
  {
    // recursively merge remaining nodes in left list with right list
    merging = left;
    merging->next = merge(left->next, right);
  }

  // date of left list is not smaller than right list
  // check if date in left list is greater than right list
  else if (left->reservation.date > right->reservation.date)
  {
    // recursively merge remaining nodes in left list with right list 
    merging = right;
    merging->next = merge(left, right->next);
  }

  // both lists have the same date
  else
  {
    // check if time in left list is earlier than right list
    if (left->reservation.time < right->reservation.time)
    {
      // recursively merge remaining nodes in left list with right list 
      merging = left;
      merging->next = merge(left->next, right);
    }

    // time in right list is earlier than left list
    else
    {
      // recursively merge remaining nodes in left list with right list 
      merging = right;
      merging->next = merge(left, right->next);
    }
  }

  // return merged list
  return merging;
}


// function will split the linked list in two
void split(Node *head, Node **first, Node **second)
{
  // declare and initialize pointers
  Node *slow = head;
  Node *fast = head->next;

  // keeps looping as long as fast pointer is not null
  while (fast != nullptr)
  {
    fast = fast->next;
    if (fast != nullptr)
    {
      // slow pointer is one node ahead and fast pointer is two nodes ahead
      slow = slow->next;
      fast = fast->next;
    }
  }

    // assign first and second pointers to the desired halves of the linked list
    // first points to the original head of list
    // back points to second half of list
    *first = head;
    *second = slow->next;
    slow->next = nullptr;
}



