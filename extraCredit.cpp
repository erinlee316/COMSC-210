

// FillBuzz Question
#include <iostream>
using namespace std;

int main()
{
  // loops runs from 1-100
  for (int i = 1; i <= 100; i++)
  {
    // check if number is multiple of three and five 
    if (i % 3 == 0 && i % 5 == 0)
      cout << "FizzBuzz ";

    // check if number is only multiple of three
    else if (i % 3 == 0)
      cout << "Fizz ";
    
    // check if number is only multiple of five
    else if (i % 5 == 0)
      cout << "Buzz ";

    // number is not a multiple of three or five
    else
      cout << i << " ";
  }

  return 0;
}