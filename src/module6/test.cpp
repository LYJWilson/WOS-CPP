/* 
*   Test 6 -- Arrays

    ? Learning Objectives
    1. Arrays
    2. Passing an array as an argument

    ! Important Tips
    1. Note the syntax of initializing arrays!
       Place a square bracket containing the array size after the variable name.
       To declare an array of a certain size, say 4 elements.. we do
       e.g. int y[4], double x[4]
       To write an array of values, we use the curly braces {}!
    2. An array starts from the zero index. This means ...
       The first element of an array is accessed with arr[0]
       The second element of an array is accessed with arr[1] and so forth.
    3. An array argument into a function is always 'pass-by-pointer' (similar to pass-by-reference)
       Any modification made to an array within the function will be made to the original array outside its scope too.
*/

#include <iostream>     // This statement imports all code from the iostream library. 

// TODO Complete the following function
void concatenateTwoArrays(int a[6], int b[3], int c[9]){

}

// The 'main' function is the starting point of every C++ program.
int main() {      
   int a[6] = {5, 2, -3, 5, 6, 2};
   int b[3] = {-2, 1, -3};
   int c[9] = { 0 }; // Note: By specifying only 1 element, we effectively initializes the entire array with the same value.

   // TODO START
   // TODO1: Complete the function 'concatenateTwoArrays', to join the two arrays a and b into a combined array c
   // ? Expected Output
   // ? -> The resulting array is: 5, 2, -3, 5, 6, 2, -2, 1, -3,
   concatenateTwoArrays(a, b, c);

   std::cout << "The resulting array is: ";
   for (int i = 0; i < 9; i++){
      std::cout << c[i] << ", ";
   }
   // TODO END

   return 0;
}