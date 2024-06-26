/* 
*   Module 2.2 -- Integer Arithmetic

    ? Learning Objectives
    1. Declare and initialize arithmetic variables (e.g. int, double)
    2. Utilize simple operators to compute variables
    3. Type-casting

    ! Important Tips
    1. All function statements are nested within the curly braces {}
    2. All function statements must end with a semicolon ;
    3. Each variable name can only be declared once
    4. Use doubles to represent decimal values! 
    5. Operators involving two integers will return a truncated integer value, unless explicitly type-casted.
*/

#include <iostream>     // This statement imports all code from the iostream library. 

// The 'main' function is the starting point of every C++ program.
int main() {      

    //* Compute the perimeter of a rectangle with integer values
    //* Here, we declare and assign perimeter in separate statements. Note that there are different ways to instantiate a value!
    int perimeter;                 // Declares the variable, 'perimeter', to have a 'int' type, without initialization.
    int x = 3;                     // Declares and initializes the variable, 'x', to have a 'int' type, and a value 3.
    int y = 5;                     // Declares and initializes the variable, 'y', to have a 'int' type, and a value 4.
    perimeter = x + x + y + y;     // Assign the value of x + x + y + y into the variable 'perimeter'.
    std::cout << "perimeter = " << perimeter << "\n";

    //* What happens if we try to divide y by x?
    //* An integer division will yield an integer!
    double z = y / x;
    std::cout << "The division of two integers = " << z << "\n";

    //? Try it together! Given integers x and y, how can we properly divide these two integers?


    //* Now, let's explore the use of modulos.
    //* Modulo gives the remainder of the division
    int res = y % x;
    std::cout << "The result of modulo = " << res << "\n";

    return 0;
}   