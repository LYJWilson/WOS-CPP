/* 
*   Module 5.2 -- Introduction to functions

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

// Function declaration/definition must be before the main function (which is the starting point of your program)
// Here, the function named 'multiplyTwoDoubles' takes in two inputs, arbitrarily named x and y. 
// It takes the two inputs it received and multiply them to a function scoped variable named 'result'
// Then, it returns the value of the result, with type double, as its output.
double multiplyTwoDoubles(double x, double y){
    double result = x * y;
    std::cout << "The value of result in multiplyTwoDoubles is " << result << "\n";
    
    return result;      // Here, we return the variable 'result', which is a 'double' type
}

// The 'main' function is the starting point of every C++ program.
int main() {      

    //* Example showing the function call
    double value1 = 10.0;
    double value2 = 8.0;

    // Here, the function named 'multiplyTwoDoubles' takes in two inputs, arbitrarily named x and y.
    // As we call the function, we pass in 'value1' into the field 'x', and 'value2' into the field 'y'.
    // The function does what it's coded to do as defined in its definition above.
    // It returns a double value which we then assign to our new double variable 'product'.
    double product = multiplyTwoDoubles(value1, value2);
    std::cout << "Product = " << product << "\n";
    
    // ? Try it together! What happens if we uncomment the following line? What happens?
    // std::cout << "value of result OUTSIDE multiplyTwoDoubles is  " << result << "\n";

    return 0;
}