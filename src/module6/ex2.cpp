/* 
*   Module 6.2 -- Arrays as a function argument

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

void addFive(int a[6]){
    for (int i = 0; i < 6; i++){
        a[i] += 5;
    }
}

// The 'main' function is the starting point of every C++ program.
int main() {      
    
    //* Add +5 to each grade
    int grades[6] = {1, 2, 1, 2, 4, 2}; // Declare & initialize an integer array, named 'grades', composing of 6 elements
    int total = 0;
    
    // An array argument into a function is always 'pass-by-pointer' (similar to pass-by-reference)
    // Any modification made to an array within the function will be made to the original array outside its scope too.
    addFive(grades);

    for (int i = 0; i < 6; i++){
        std::cout << "Element #" << i << " = " << grades[i] << "\n"; // Notice how my grades on the main scope has been changed by the above function?
    }

    return 0;
}