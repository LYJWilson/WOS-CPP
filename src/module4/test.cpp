/* 
*   Test 4 -- Loops

    ? Learning Objectives
    1. For loops
    2. While loops

    ! Important Tips
    1. Note the syntax (i.e. grammar) of the for loop! 
       The condition(s) are contained within brackets and separated by semi-colons 
       (initial condition; terminating condition; what to do after each loop)
       The statements within the for-loop should be contained within the curly braces {} 
    2. Note the syntax (i.e. grammar) of the while loop!
       The condition to remain in the while loop are contained within brackets ()
       The statements within the while-loop should be contained within the curly braces {} 
    3. Beware of infinite while loop! If your condition is always true, your program might run infinitely!
    4. Break is used to 'break out' of the loop.
    5. Continue is used to 'skip' the current iteration of the loop. 
*/

#include <iostream>     // This statement imports all code from the iostream library. 

// The 'main' function is the starting point of every C++ program.
int main() {      

    // TODO START
    // ? Expected Output

    // ? Program STARTS
    // ? >> Input any integer between 1 - 10: 5
    // ? -> *
    // ? -> **
    // ? -> ***
    // ? -> ****
    // ? -> *****
    // ? >> Input any integer between 1 - 10: 3
    // ? -> *
    // ? -> **
    // ? -> ***
    // ? >> Input any integer between 1 - 10: 11
    // ? Program EXITS

    int h = 5;

    // TODO1: Using a while loop, continuously prompt the user for an integer height between 1 - 10. \
    // TODO1  If the user inputs any value outside the range [1 - 10], exit the while loop and stop the program.  (~4 LOCs)
    
    // Hint: The current code prompts the user ONCE for an integer between 1 - 10. 
    // Wrap the code inside your while loop to repeatedly prompt the user for an input & assign to the variable 'h'
    // Implement an exit condition to exit the while loop. There are many ways to do this! Do you remember what can be used?
    // Remember to wrap all lines of code (including those in TODO2) that you wish to execute in your while loop.
    std::cout << "Input any integer between 1 - 10: ";
    std::cin >> h;
    
    // ! Challenging
    // TODO2: Using a nested for-loop (i.e. a for-loop inside another for-loop), print a triangle of asteriskss with height = h. (~6 LOCs)



    // TODO END

    return 0;
}