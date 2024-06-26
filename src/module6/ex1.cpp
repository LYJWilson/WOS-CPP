/* 
*   Module 6.1 -- Arrays

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

// The 'main' function is the starting point of every C++ program.
int main() {      
    
    //* Add +5 to each grade
    int grades[6] = {1, 2, 1, 2, 4, 2}; // Declare & initialize an integer array, named 'grades', composing of 6 elements

    int total = 0;
    // An array starts from the zero index. We can access specifics element by using square brackets []
    // The first element is accessed with [0]. Second element accessed with [1] and so forth...
    for (int i = 0; i < 6; i++){
        std::cout << "idx = " << i << ", Original score = " << grades[i];
        grades[i] += 5;                 
        std::cout << " -> final score = " << grades[i] << "\n";
    }

    //* Sum of squares
    double vector[3] = {1.5, -2.0, 5.9}; // Declare & initialize an double array, named 'vector', composing of 3 elements
    double sum_of_squares = 0;

    for (int i = 0; i < 3; i++){
        sum_of_squares += vector[i] * vector[i];
    }

    std::cout << "Sum of squares = " << sum_of_squares << "\n";

    return 0;
}