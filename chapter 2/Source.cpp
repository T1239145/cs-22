/*
                                       2.3 linear and binary search


#include <iostream>  (linear search ex)
using namespace std;

int LinearSearch(int* numbers, int numbersSize, int key) {
   for (int i = 0; i < numbersSize; i++) {
      if (numbers[i] == key) {
         return i;
      }
   }
   return -1; // not found
}

int main() {
   int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   cout << "NUMBERS: [" << numbers[0];
   for (int i = 1; i < numbersSize; i++) {
      cout << ", " << numbers[i];
   }
   cout << "]" << endl;

   // Prompt for an integer to search for
   cout << "Enter an integer value: ";
   int key = 0;
   cin >> key;

   int keyIndex = LinearSearch(numbers, numbersSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }


   (binary search ex)

   #include <iostream>
using namespace std;

int LinearSearch(int* numbers, int numbersSize, int key) {
   for (int i = 0; i < numbersSize; i++) {
      if (numbers[i] == key) {
         return i;
      }
   }
   return -1; // not found
}

int main() {
   int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   cout << "NUMBERS: [" << numbers[0];
   for (int i = 1; i < numbersSize; i++) {
      cout << ", " << numbers[i];
   }
   cout << "]" << endl;

   // Prompt for an integer to search for
   cout << "Enter an integer value: ";
   int key = 0;
   cin >> key;

   int keyIndex = LinearSearch(numbers, numbersSize, key);
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index ";
      cout << keyIndex << "." << endl;
   }
   BinarySearch(numbers, low, high, key) {
   if (low > high)
      return -1

   mid = (low + high) / 2
   if (numbers[mid] < key) {
      return BinarySearch(numbers, mid + 1, high, key)
   }
   else if (numbers[mid] > key) {
      return BinarySearch(numbers, low, mid - 1, key)
   }
   return mid
}

                                    2.4 (constant time operations)

constant time operation always operates on the same ount of time regardless of input
ex 
x= 10,y=5 , x * y =z , for (i = 0; i < 10; i++) sum += y

division is often slower

                                    2.5(growth of functions and complexity)

Lower bound: A function f(N) that is ? the best case T(N), for all values of N ? 1.
Upper bound: A function f(N) that is ? the worst case T(N), for all values of N ? 1.

sections a bit confusing

asymptotic notation-
                                2.6( o notation)
                                2.7 (algorithm analysis)

Which function best represents the number of operations in the worst-case?

i = 0
sum = 0
while (i < N) {
   sum = sum + numbers[i]
   ++i
}
f(n) = 3n +3 us wirst case operation

                            2.8 )recursive definitions)
recursive breaks algorithim into smaller parts and applies algorithm throughouyt
calls itself ex
Factorial(N) {
   if (N == 1)
      return 1
   else
      return N * Factorial(N - 1)
}

ex 2
If Factorial(6) is called, how many additional calls are made to Factorial to compute the result of 720?
6! = 1*2*3*4*5*6 = 720
answer is 5 additional calls 
                        2.9

Fibonacci sequence is a numerical sequence where each term is the sum of the previous 2 terms in the sequence,
fibonacci(8) = 0,1,start 1,2,3,5,8,13,21 =returns 21

*/

