/* 
*   Module 3.1 -- Logics with Simple Booleans

    ? Learning Objectives
    1. Booleans (i.e. true / false)
    2. Comparison operators
    3. If-else conditions
    4. char type

    ! Important Tips
    1. Booleans take the values of (true / false). These are equivalent to (1/0)
    2. Note the syntax (i.e. grammar) of the if-else loop! 
       The condition(s) are contained within brackets ()
       The statements within each if-else subblocks should be contained within the curly braces {} 
    3. Multiple conditions can be checked by using the AND (&&) and OR (||) operators.
    4. If-else loops considers each condition sequentially. It processes the statements within the first condition that it fulfills.
    5. 'char' type is enclosed with single quotes, while "string" is enclosed with double quotes
*/

#include <iostream>     // This statement imports all code from the iostream library. 

// The 'main' function is the starting point of every C++ program.
int main() {      

    //* This code illustrates the simple use of booleans for if-else conditions
    bool gotPineapple = false;
    bool gotPen = true;

    //* Checking if a condition is true
    // This is the first if-else loop, checking if gotPen == true
    // Note, (gotPen == true) is equivalent to (gotPen)
    if (gotPen == true) {                   // Conditional check if gotPen == true. Note the double equality sign for comparison
        std::cout << "I've got a pen \n";
    }

    else {
        std::cout << "I've got no pen \n";
    }

    //* Checking if a condition is false
    // This is the second if-else loop, checking if gotPineapple == false. 
    // Note, (gotPineapple == false) is equivalent to (!gotPineapple) 
    if (gotPineapple == false) {
        std::cout << "I've got no pineapple \n";
    }

    else {
        std::cout << "I've got a pineapple \n";
    }

    //* Checking for multiple conditions
    //* Use AND (&&) and OR (||) for multiple conditions
    // This is the third if-else loop, checking if both gotPen == true and gotPineapple == true
    if (gotPen && gotPineapple) { // Note the different methods of checking boolean conditions!
        std::cout << "I've got pineapple pen \n";
    }

    // The OR operator (||)
    //? Try it together! How can we check if we gotPen OR gotPineapple?

    std::cout << "Values of gotPen is " << gotPen << " and gotPineapple is " << gotPineapple << "\n";

    return 0;
}   