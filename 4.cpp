//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 4
//        Date: 10/24/2023
//     Problem: You finished the school week and received a lot of homework to complete over the weekend.
//              You look through your assignments and want to use a priority queue to enter approximately 
//              how long it will take to complete each assignment via minutes. The assignments with a 
//              higher value will receive priority, as it takes the longest time to complete. The assignments
//              with a lower value will receive less priority, as it takes the shortest time to 
//              complete. Once you complete the assignment, you can remove the highest priority number.
//              You can also check to see how many minutes approcimately it takes to complete the next assignment,
//              whether you finished all your assignments, and check the remaining number of assignments left. 
// Description: Program will implement a prioritiy queue (enqueue, dequeue, peek, isempty, getlength) 
//              and demonstrate its basic operations.
//************************************************************************************************************

#include <iostream>
#include <queue>
using namespace std;

// function prototype
void enqueue(priority_queue<int>&);
void dequeue(priority_queue<int>&);
void peekQueue(priority_queue<int>&);
void checkEmpty(priority_queue<int>&);
void getLength(priority_queue<int>&);
void display(priority_queue<int>&);

int main()
{
  // create a priority queue
  priority_queue<int> pq;

  // declare and initialize variable
  int option = 0;

  // get user input
  cout << "(1 - add, 2 - remove, 3 - peek, 4 - check empty, 5 - get length, 6 - quit)" << endl;
  cout << "Choose an option (1-6): ";
  cin >> option;

  // keeps looping until user inputs 6
  while (option != 6)
  {
    // choices available depending on user's input
    switch(option)
    {
      // function call to insert element into queue
      case 1:
        enqueue(pq);
        cout << endl;
        break;

      // function call to remove top element of queue  
      case 2:
        dequeue(pq);
        cout << endl;
        break;

      // function call to peek into queue
      case 3: 
        peekQueue(pq);
        cout << endl;
        break;

      // function call to check queue is empty or not
      case 4: 
        checkEmpty(pq);
        cout << endl;
        break;

      // function call to get size of queue
      case 5: 
        getLength(pq);
        cout << endl;
        break;

      // user input is not (1-6)
      default:
        cout << "Invalid input. Try again.\n" << endl;
            cout << "(1 - add, 2 - remove, 3 - peek, 4 - check empty, 5 - get length, 6 - quit)" << endl;
    cout << "Choose an option (1-6): ";  
    cin >> option;
        break;
      }

    // asks for user input again

  }

  // user input is 6, program is ending
  cout << "Program ending...\n" << endl;
  return 0;
}


// function inputs the estimated time to complete one assignment and adds it to the priority queue
void enqueue(priority_queue<int>& pq)
{
  // declare and initialize variable
  int userInput;

  // get user input and add into queue
  cout << "Enter estimated minutes to complete assignment: ";
  cin >> userInput;
  pq.push(userInput);
}


// function will remove the top number in the queue if there are numbers inside
// function will return back to main function if queue is empty
void dequeue(priority_queue<int>& pq)
{
  // declare and initialize variable
  int topElement = 0;

  // queue is empty
  if (pq.empty())
    cout << "Priority queue is empty. Cannot remove assignment with highest priority." << endl;

  // queue is not empty, pop off top element
  else
  {
    topElement = pq.top();
    cout << "Removing assignment with estimated time: " << topElement << " min" << endl;
    pq.pop();
  }
}


// function peeks into queue and determines if numbers exist inside
void peekQueue(priority_queue<int>& pq)
{
  // queue is not empty, so shows the next estimated time in minutes
  if (!pq.empty())
    cout << "Estimated time to complete next assignment: " << pq.top() << " min" << endl;

  // queue is empty
  else 
    cout << "Priority queue is empty. Cannot peek." << endl;
}


// function determines if queue is empty or not
void checkEmpty(priority_queue<int>& pq)
{
  // queue is not empty, assignments still have to be completed
  if (!pq.empty())
  {
    cout << "Priority queue is not empty." << endl;
    display(pq);
  }

  // queue is empty, no assignments left to be completed
  else
    cout << "Priority queue is empty. No assignments need to be completed." << endl;
}


// function displays the size of priority queue
void getLength(priority_queue<int>& pq)
{
  // display size of priority queue
  cout << "Number of assignments to be completed: " << pq.size() << endl;
}
 

// function makes a copy of the existing priority queue to display the elements inside
void display(priority_queue<int>& pq)
{
  // declare and intialize variable
  priority_queue<int> temp = pq;

  cout << "Assignments need to be completed in this order: ";

  // display top element in priority queue, then remove it until queue is empty
  while(!temp.empty())
  {
    cout << temp.top() << " min    ";
    temp.pop();
  }

  cout << endl;
}
