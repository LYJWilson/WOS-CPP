/* 
*   Test 5 -- Function and scopes

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
    
// TODO START
// Hint: Define your functions here (above the 'main' function)







// The 'main' function is the starting point of every C++ program.
int main() {      

    // TODO1: Write a function, named "meanOfThreeIntegers", to receive three integers and return their mean (i.e. average) value (~4 LOCs)
    // ? Expected Output
    // ? -> The mean value is 5.6667

    int a1 = 3;
    int a2 = 4;
    int a3 = 10; 

    // Hint: The function below has not be defined yet. Write your function and uncomment the following statement to test!
    // std::cout << "The mean value is " << meanOfThreeIntegers(a1, a2, a3) << "\n";

    // TODO2: Write a pass-by-reference function, with a return type 'void', to swap the values of x and y (~4 LOCs)
    // ? Expected Output
    // ? -> Initial values of x = 11, y = -3
    // ? -> SWAPPED values of x = -3, y = 11
    int x = 11;
    int y = -3;

    std::cout << "Initial values of x = " << x << ", y = " << y << "\n";

    // Hint: The function below has not be defined yet. Write your function and uncomment the following statement to test!
    // swapValues(x, y);
    
    std::cout << "SWAPPED values of x = " << x << ", y = " << y << "\n";


    // TODO END

    return 0;
}