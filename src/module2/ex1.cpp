/* 
*   Module 2.1 -- Double Arithmetic

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

    //* Compute the area of a rectangle with double values. Use doubles to represent decimal values.
    double x = 3.9;                              // Declares and initializes the variable, 'x', to have a 'double' type, and a value 3.9.
    double y = 4.3;                              // Declares and initializes the variable, 'y', to have a 'double' type, and a value 4.3.
    double area = x * y;                         // Declares and initializes the variable, 'area', to have a 'double' type, and a value of x * y.
    std::cout << "area = " << area << "\n";

    //* Compute the ratio of the length:breadth of the rectangle (x, y)
    double ratio = y / x;                       // Declares and initializes the variable, 'ratio', to have a 'double' type, and a value of y / x.
    std::cout << "ratio = " << ratio << "\n";

    return 0;
}   