/* 
*   Module 1.1 -- Hello World!

    ? Learning Objectives
    1. Building your first executable using CMake
    2. Pre-processing directives (#)
    3. Comments
    4. IO Statements
    5. Strings

    ! Important Tips
    1. All function statements are nested within the curly braces {}
    2. All function statements must end with a semicolon ;
    3. Each variable name can only be declared once
    4. Strings are contained by double quotes ""
*/

#include <iostream> // There are several useful standard libraries in C++.
                    // This statement imports all code from the iostream library. 
                    // iostream contains standard console input/output functions, such as print statements

/* a. Function named 'main'. By default, the 'main' function is the starting point of every C++ program.
   b. The term preceeding the function name specifies the return type. 
      In this case, 'int' informs the compiler that an integer type return variable is expected.
   c. The terms in the brackets () following the function name are known as arguments.
       In this case, there are no additional function arguments specified in this function.
   d. All function statements are nested within the curly braces {}
   e. All function statements must end with a semi-colon ;
*/
int main() { 

    //* Simple output statement
    //? Try it together! Change the string below and recompile your program. Does your output change?
    std::cout << "Hello World! \n"; // Character output (i.e. cout) to print "Hello World". "\n" is a new-line character.
    
    return 0; // 0 denotes no error
}   