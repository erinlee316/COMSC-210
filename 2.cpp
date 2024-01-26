//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 2
//        Date: 9/12/2023
//     Problem: Annabelle is sorting through her old quizzes she took throughout the semester. She has a total
//              of 30 quizzes, and she wants to place them in ascending order based on the scores to determine 
//              what topics she should study first.
// Description: Program uses merge sort to organize a pre-defined array of 30 elements into ascending order.
//              Program will use recursions to break array into subarrays and will call multiple functions
//              to execute this sorting algorithm. The unsorted and sorted array will be displayed. Summary
//              about merge sort's time complexity will also be displayed.
//************************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;


// function prototypes
void displayArray(int[], int);
void mergeSortDown(int[], int, int);
void mergeSortUp(int[], int, int, int);
void summary();


// global variable
const int MAX = 30;


int main()
{
  // declare and initialize variables
  int scores_size = 0;
  int allScores[MAX] = {24, 90, 85, 94, 28, 74, 49, 62, 40, 80,
                        19, 10, 88, 47, 72, 85, 94, 93, 99, 100,
                        87, 89, 70, 62, 80, 94, 97, 64, 59, 95};

  // determines how many elements in array by dividing total bytes with bytes of first element
  scores_size = sizeof(allScores) / sizeof(allScores[0]);

  // function call and display unsorted array 
  cout << "Scores before sorting with merge sort:" << endl;
  displayArray(allScores, scores_size);

  // function call for merge sort
  mergeSortDown(allScores, 0, scores_size - 1);

  // function call to display array after merge sort
  cout << "Scores after sorting with merge sort:" << endl;
  displayArray(allScores, scores_size);

  // function call to display summary of time complexity
  summary();
  
  return 0;
}


// function displays contents of array before and after sorting
void displayArray(int scores[], int scoresSize)
{
  for (int i = 0; i < scoresSize; i++)
  {  
    if (i < scoresSize - 1)
      cout << scores[i] << ", ";

    else
      cout << scores[i];
  }

  cout << endl << endl;
}


// function divides array into half until the array reaches one element inside (can no longer divide itself)
void mergeSortDown(int newArrayScores[], int left, int right)
{
  // declare and initialize variable
  int middle = 0;
  
  // compare index value of left variable and right variable, then divide array in half if array has more than one element
  // keeps recursive pattern until single element remains in array
  if (left < right)
  {

    // calculate middle index of array
    middle = left + (right - left) / 2;

    // function performs recursion to split current array into two separate arrays until one element array occurs
    // defines left portion of array
    mergeSortDown(newArrayScores, left, middle);

    // defines right portion of array
    mergeSortDown(newArrayScores, middle + 1, right);

    // function will sort numbers in ascending order  
    mergeSortUp(newArrayScores, left, middle, right);
  }
}


// function takes in new arrays and sorts the elements into ascending order
void mergeSortUp(int newArrayScores[], int left, int middle, int right)
{
  // declare and initialize variables
  int leftLength = middle - left + 1;
  int rightLength = right - middle;

  // keeps track of index in left, right, and merged arrays
  int tempLeftIndex = 0;
  int tempRightIndex = 0;
  int mergedIndex = left;

  // temporary arrays will hold newly sorted elements
  int tempLeftArray[leftLength]; 
  int tempRightArray[rightLength];

  // places elements into temporary left array before sorting
  for (int i = 0; i < leftLength; i++)
    tempLeftArray[i] = newArrayScores[left + i];

  // places elements into temporary right array before sorting
  for (int j = 0; j < rightLength; j++)
    tempRightArray[j] = newArrayScores[middle + 1 + j];

  // keeps looping until index becomes larger than the very right index of original array
  while (mergedIndex <= right)
  {
    // element from temp left array will merge up into original array
    if ((tempLeftIndex < leftLength) && (tempRightIndex >= rightLength || 
          tempLeftArray[tempLeftIndex] <= tempRightArray[tempRightIndex]))
      {
        newArrayScores[mergedIndex] = tempLeftArray[tempLeftIndex];
        tempLeftIndex++;
      }

    // element from temp right array will merge up into original array
    else
    {
      newArrayScores[mergedIndex] = tempRightArray[tempRightIndex];
      tempRightIndex++;
    }

    // increments by one to fill original array with elements from left and right temp arrays
    mergedIndex++;
  }
}


// function will display time complexity summary of merge sort
void summary()
{
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << setw(80) << "Summary: Time Complexity of Merge Sort\n" << endl;
  cout << "Merge sort has a time complexity of O(n*log n), where n represents the program's input size.\n" << endl;
  cout << "Why is it O(n*log n)?" << endl;
  cout << "1. Algorithm uses divide and conquer technique, making the time complexity O(log n + 1)." << endl;
  cout << setw(122) << "-At each iteration, the number of elements in the array splits in half (n/2) until one element is left in the array." << endl;
  cout << setw(71) << "-We do not know how many times this recursion must occur (n/2^k)." << endl;
  cout << setw(115) << "-To determine the value of k, this process will use logarithms, hence, having a time complexity of O(log n). " << endl;
  cout << setw(122) << "-Merge sort has a time complexity of O(1) while executing recursives because it must perform arithmetic operations.\n" << endl;
  cout << "2. When this sorting algorithm merges the temporary arrays back into the original array, it has a time complexity of O(n)." << endl;
  cout << setw(105) << "-It takes the two split arrays and adds them together when placing the elements in ascending order." << endl;
  cout << setw(75) << "ex: left array: n/2, right array n/2 --> n/2 + n/2 = 2n/2 or n\n" << endl;
  cout << "3. To calculate the actual time complexity of merge sort, you multiple both time complexities together:" << endl;
  cout << setw(48) << "O(n) * O(log n + 1) = O(n*log n + n)" << endl;
  cout << setw(45) << "= O(n*log n)\n" << endl;
}

