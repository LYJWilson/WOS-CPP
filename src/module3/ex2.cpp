/* 
*   Module 3.2 -- Logics with Numerical Comparisons

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

    //* This code checks if the score should be rated as distinction, merit, or ungraded
    //? Try it together! What happens if we check merit score before distinction score? Will your code still work as expected?
    
    int score;
    std::cout << "Input any integer between 0 to 100: ";
    std::cin >> score; // Saves the value of user input into variable score

    int minDistinctionScore = 70;
    int minMeritScore = 60;

    char letterGrade;                          // Declares the variable, 'letterGrade', to have a 'char' type.

    //* If-else-if conditions
    if (score >= minDistinctionScore) {        // First, we check if the grade is distinction. If it is, we assign 'A' to letter grade
        letterGrade = 'A';                     // Note: 'char' type is enclosed with single quotes, while "string" is enclosed with double quotes
    }

    else if (score >= minMeritScore) {         // If its not distinction, we check if the grade is Merit. If it is, we assign 'B' to letter grade
        letterGrade = 'B';
    }

    else {                                     // If its neither Distinction nor Merit, we assign 'U' to the letter grade
        letterGrade = 'U';
    }

    std::cout << "Your grade is = " << letterGrade << "\n";

    return 0;
}   