/* 
*   Test 3 -- Logics

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

    // TODO START
    // ? Expected Output(s)
    // ? >> Input any integer between -100 to 100: -3
    // ? -> Number is odd
    // ? -> Number is negative

    // ? >> Input any integer between -100 to 100: 0
    // ? -> Number is even
    // ? -> Number is zero

    // ? >> Input any integer between -100 to 100: 90
    // ? -> Number is even
    // ? -> Number is positive

    int x;
    std::cout << "Input any integer between -100 to 100: ";
    std::cin >> x; // Saves the value of user input into variable x

    // TODO1: Check if x is odd or even. Display your result. (~6 LOCs)





    // TODO2: Check if x is negative, positive, or exactly equal to 0. Display your result (~9 LOCs)
    
    
    

    // TODO END

    return 0;
}   