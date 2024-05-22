/* 
*   Test 1 -- IO Functions

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
   b. The term preceeding the function name specifies the return type. In this case, 'void' informs the compiler that no return variable is expected.
   c. The terms in the brackets () following the function name are known as arguments.
       In this case, there are no additional function arguments specified in this function.
   d. All function statements are nested within the curly braces {}
   e. All function statements must end with a semi-colon ;
*/
void main() { 

    // TODO START
    // TODO1: Create an character input to store the user's school name into the variable 'schoolname'. (~1 LOCs)
    // TODO2: Output a welcome message with the user's input school name. (~1 LOCs)
    // ? Expected Output
    // ? >> Please input your school name and press Enter: WOS College
    // ? -> Hello, student of WOS College!
    
    // The code below prompts the user for their school name but does not wait nor return anything. 
    // Please fix the code to fulfil the expected output.
    std::string schoolname;
    std::cout << "Please input your school name and press Enter: "; 



    // TODO END
}   