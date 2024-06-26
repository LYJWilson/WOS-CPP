/* 
*   Module 5.1 Scope

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

// The 'main' function is the starting point of every C++ program.
int main() {      
    
    //* Example to demonstrate the scope of different variables.
    //* Here, we compute the sum of squared numbers from 0-5.

    // Variables declared in the outermost {} of the main() function has function scope.
    // These variables will cease to exist once the program has exited the function.
    int sum_mainscope = 0;

    for (int i_blockscope = 0; i_blockscope < 5; i_blockscope++)
    {   
        // Variables declared within these curly braces {} have block scope.
        // These variables will cease to exist once the program has exited the block.
        int i_blockscope_sq = i_blockscope * i_blockscope;

        sum_mainscope += i_blockscope_sq; // Inner blocks can access variables with outer scope

        std::cout << "The intermediate value of i_blockscope_sq is " << i_blockscope_sq << "\n";
        std::cout << "The intermediate sum is " << sum_mainscope << "\n";
    }

    std::cout << "The final sum is " << sum_mainscope << "\n\n";

    // ? Try it together! What happens if we uncomment the following line? What happens?
    // std::cout << "The last value of i_blockscope_sq is " << i_blockscope_sq << "\n";

    //* Example to illustrate how an inner scope re-declaration hides an outer scope
    // In this case, sum_mainscope is re-declared in the inner curly braces {}
    // Therefore, any modification to the re-declared sum_mainscope within the inner block scope shall only affect the inner_block's sum_mainscope
    {
        // Here we re-declare sum_mainscope in a inner block scope
        int sum_mainscope;
        sum_mainscope = 2; // We assign sum_mainscope with the value 2.
                           // Since this variable was re-declared in the inner block scope, any changes shall only affect this inner block variable.

        // Here, the print statement will print the modified inner block variable (as the outer scope variable is masked)
        std::cout << "The inner block sum is " << sum_mainscope << "\n"; 
    }
    // Once we exit from the inner curly braces {}, the re-declared sum_mainscope ceased to exist, and the original outer scope variable prevails.
    std::cout << "The final sum is after inner block modification is " << sum_mainscope << "\n";

    return 0;
}