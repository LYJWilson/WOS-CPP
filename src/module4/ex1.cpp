/* 
*   Module 4.1 -- For Loops

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

    //* This code demonstrates the syntax of a for loop
    //? Try it together! Can you achieve the same result with a decrement counter?

    int sum1 = 0;
    for (int i = 0; i < 5; i++) { // For a 'int' variable, i, starting from 0, increment i by 1 for as long as i < 5. i++ is equivalent to i = i + 1
        sum1 += i;                 // This is equivalent to sum1 = sum1 + i
        std::cout << "At i = " << i << ", Sum1 = " << sum1 << "\n";
    }
    std::cout << "\n";
    
    //* This code demonstrates the use of continue and break
    int sum2 = 0;
    int j = 0;
    for (j = 0; j < 20; j+=2) { // For a 'int' variable, j, starting from 0, increment j by 2 for as long as j < 20.

        if (j == 6) {
            continue;
        }

        if (j == 12) {
            break;
        }

        sum2 += j;                    // This is equivalent to sum2 = sum2 + j
        std::cout << "At j = " << j << ", Sum2 = " << sum2 << "\n";
    }

    std::cout << "Final j = " << j << ", Sum2 = " << sum2 << "\n";

    return 0;
}