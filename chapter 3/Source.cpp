/*
				3.2(selection sort)
example 1
Given list (5, 9, 8, 7, 6) and i = 1, 
what will be the list after completing the second outer loop iteration? Type answer as: 1, 2, 3
answer 5,6,8,7,9
exaMPLE 2
about how many times longer will sorting a list of 
2x elements take compared to sorting a list of x elements

answer 4
(2x^2)/x^2 = 4x^2 /x^2 = 4
example 3
When using selection sort, how many times longer will sorting a list of 54 
 elements take compared to sorting a list of 6 
 elements?

 answer
(54/6)^2 = 9^2 =81

							3.3(selection sort)

							3.4(insertion sort)
left to right 
only a single comparison is needed for arrays in order
nearly sorted- 1 item out of order
O((N - C) * 1 + C * N) = O(N).

example 1
Given list (10, 11, 12, 13, 14, 7), how many comparisons will be made during the final outer loop execution
answer 5
example 2
Given list (18, 23, 34, 75, 3), how many total comparisons will insertion sort require?
answer 7
							3.5(insertion sort)

If the numbers array has 4 elements in descending order, 
then the InsertionSort() function does _____ swaps.
answer 6
                            3.6(shell sort)

interleaved list sorts each list individually
gap value = number of interleaved list being sorted


                            3.8( quicksort)
ex 1 how many levels are required for a list of 1024 elements
formula n-1
answer 1023
ex 2
How many total calls to the Quicksort() function are made to sort a list of 1024 elements?
1+2*(1024-1) 
answer 2047

                    3.10(merge sort)

divides a list into two halves recursively sorts each/until a list of 1 element is reached
j=(i+k)/2
to the right is j+1
merge() function

ex how many recursive partitioning levels are required for a list of 8 elements
logbase 2 8 = 3


               3.12(radix sort)

designed for integers
bucket sort

*/

#include <iostream>
#include <string>
using namespace std;

void InsertionSort(int* numbers, int numbersSize) {
    for (int i = 1; i < numbersSize; i++) {
        int j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            // Swap numbers[j] and numbers [j - 1]
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            j--;
        }
    }
}

string ArrayToString(int* array, int arraySize) {
    // Special case for empty array
    if (0 == arraySize) {
        return string("[]");
    }

    // Start the string with the opening '[' and element 0
    string result = "[" + to_string(array[0]);

    // For each remaining element, append comma, space, and element
    for (int i = 1; i < arraySize; i++) {
        result += ", ";
        result += to_string(array[i]);
    }

    // Add closing ']' and return result
    result += "]";
    return result;
}

int main() {
    // Create an array of numbers to sort
    int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
    int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

    // Display the contents of the array
    cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;

    // Call the InsertionSort function
    InsertionSort(numbers, numbersSize);

    // Display the sorted contents of the array
    cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}

/*
* void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
                                             // array for merged numbers
   int mergePos = 0;                         // Position to insert merged number
   int leftPos = leftFirst;                  // Initialize left partition position
   int rightPos = leftLast + 1;              // Initialize right partition position
      
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
      }
      mergePos++;
   }
      
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
   }
   
   // Copy merged numbers back to numbers
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
   }
   
   // Free temporary array
   delete[] mergedNumbers;
}
   
void MergeSort(int* numbers, int startIndex, int endIndex) {
   if (startIndex < endIndex) {
      // Find the midpoint in the partition
      int mid = (startIndex + endIndex) / 2;

      // Recursively sort left and right partitions
      MergeSort(numbers, startIndex, mid);
      MergeSort(numbers, mid + 1, endIndex);
            
      // Merge left and right partition in sorted order
      Merge(numbers, startIndex, mid, endIndex);
   }
}

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }
   
   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);
   
   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }
   
   // Add closing ']' and return result
   result += "]";
   return result;
}

int main() {
   // Create an array of numbers to sort
   int numbers[] = { 61, 76, 19, 4, 94, 32, 27, 83, 58 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
      
   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;
      
   // Call the MergeSort function
   MergeSort(numbers, 0, numbersSize - 1);
      
   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}

*/