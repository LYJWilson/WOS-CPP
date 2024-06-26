/* 
*   Module 5.3 -- pass-by-value VS pass-by-referencce

    ? Learning Objectives
    1. Scopes (Global, function, block)
    2. Functions
    3. Pass by reference / Pass by value

    ! Important Tips
    1. In general, the order of visibility is Global > Function > Block. 
       Inner scopes can access variables from its parent scopes
    2. By re-declaring a variable in an inner scope, one will hide/mask the original outer scope variable. 
       Any modifications in the inner scope will not affect the original outer scope variable.
    3. Note the syntax (i.e. grammar) of a function! 
       The term preceeding the function name specifies the return type -> functions must return its stated type
       The terms in the brackets () following the function name are known as arguments, which can be used by the function.
       All functions must be declared before it is called.
*/

#include <iostream>     // This statement imports all code from the iostream library. 

// This is a GLOBAL variable. It can be access by any function within this file.
int GBL_CONST_TO_ADD = 10;

// Function declaration/definition must be before the main function (which is the starting point of your program)
// This function returns void (i.e. no return value is expected)
void modifyInputByValue(int x){     // Notice the syntax without the ampersand &. This denotes the variable is pass-by-value
    x = x + GBL_CONST_TO_ADD;       // Notice how we can access the value of GBL_CONST_TO_ADD here?
    std::cout << "2. Value of x INSIDE pass by value = " << x << "\n";
}

// This function returns void (i.e. no return value is expected)
void modifyInputByReference(int& x){ // Notice the ampersand &. This denotes that the variable is pass-by-reference
    x = x + GBL_CONST_TO_ADD;        // Notice how we can access the value of GBL_CONST_TO_ADD here?
    std::cout << "4. Value of x INSIDE pass by reference = " << x << "\n";
}

// The 'main' function is the starting point of every C++ program.
int main() {      

    //* Example showing the difference between pass-by-value vs pass-by-reference
    int x = 10;

    std::cout << "1. Value of x INITIAL = " << x << "\n";
    modifyInputByValue(x);
    std::cout << "3. Value of x OUTSIDE pass by value = " << x << "\n";
    modifyInputByReference(x);
    std::cout << "5. Value of x OUTSIDE pass by reference = " << x << "\n";

    return 0;
}