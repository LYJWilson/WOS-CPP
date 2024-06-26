/* 
*   Module 4.2 -- While Loops

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

    //* This code demonstrates the syntax of a while loop
    double i = 30;

    while (i > 3) { // While the condition (i > 3) is true, execute the code within the {}
        i = i / 2.0;
        std::cout << "Value of i = " << i << "\n";
    }

    //* This code demonstrates a random number generator that gives a random ODD number between 0 - 19.
    //? Try it together! What happens if we don't use srand(time(0))? Does your code behave as expected?
    int randomNum = 0;      // Default a random number to 0
    srand(time(0));         // Define a random seed based on the current time

    while (true) {
        randomNum = rand() % 20;    // generate a random number between 0 - 19

        if (randomNum % 2 == 1) {   // If number is ODD (i.e. remainder of 1 when divided by 2), then break out of while loop
            break;
        }
    }

    std::cout << "Final random number = " << randomNum;

    return 0;
}