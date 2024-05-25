/* 
*   [INSTRUCTOR COPY]
*   Project -- Tic Tac Toe 

    ? Learning Objectives
    1. Piece everything you've learnt so far!

    ! Important Tips
    1. Assign 'O' for player action, 'X' for opponent action
    2. An array argument into a function is always 'pass-by-pointer' (similar to pass-by-reference)
       Any modification made to an array within the function will be made to the original array outside its scope too.
*/

#include <iostream>

// TODO1: Complete this function    
// Hint: If the cell corresponding to the input does not already have an 'X' or 'O', assign 'O' to the corresponding cell.
//       Else, prompt the user for a valid command again
void generatePlayerAction(char cell[9]){
    int input = 0;
    std::cout << "Choose a valid number [0-8] ";
    std::cin >> input;

    while(cell[input] == 'X' || cell[input] == 'O'){
        std::cout << "Choose a valid number [0-8] ";
        std::cin >> input;
    }
    cell[input] = 'O';
}

// TODO2: Complete this function
// Hint: Return True if 3-in-a-row is formed. Otherwise, return false.
bool checkVictory(char cell[9]) {

    // Check 3-in-a-row or 3-in-a-column
    for (int i = 0; i < 3; i++){
        if ((cell[i*3] == cell[i*3+1] && cell[i*3+1] == cell[i*3+2]) || // Check each row
            (cell[i] == cell[i + 3] && cell[i + 3] == cell[i + 6]))     // Check each column
        {
            return true;
        }
    }

    // Check diagonals
    if ((cell[0] == cell[4] && cell[4] == cell[8]) ||  
        (cell[2] == cell[4] && cell[4] == cell[6])) 
    {
        return true;
    }

    return false; // If none of the above was true, means no 3-in-a-row yet. Return false.
}

// TODO3: Complete this function
// Hint: Return True if all the cells have been filled. Otherwise, return false.
//       If at least one cell doesn't contain either 'X' or 'O', it means that the board is not completely filled.
bool checkBoardFilled(char cell[9]) {
    for (int i = 0; i < 9; i++) {
        if (cell[i] != 'X' && cell[i] != 'O') {
            return false;
        }
    }

    // If none of the cell is holding onto a 'digit', means all grids are filled.
    return true;
}

// TODO4: Complete this function
// Hint: Similiar to TODO1, now mimic an opponent action using a random number generator to generate values [0-8]
//       While the input is not valid, keep generating a random number. 
//       Once the valid random number is found, assign 'X' to the cell.
void generateOpponentAction(char cell[9]){
    int opponentInput = rand() % 9;
    while(cell[opponentInput] == 'X' || cell[opponentInput] == 'O'){
        opponentInput = rand() % 9;
    }
    cell[opponentInput] = 'X';
}

void printMap(char cell[9]){
    std::cout << "\n|-----------|\n";
    for (int i = 0; i < 3; i++){
        std::cout << "| ";
        for (int j = 0; j < 3; j++){
            std::cout << cell[i * 3 + j] << " | ";
        }
        std::cout << "\n|-----------|\n";
    }
    std::cout << "\n";
}

void main() {

    srand(time(0));
    
    char cell[9] = { '0', '1', '2', 
                     '3', '4', '5', 
                     '6', '7', '8' };

    printMap(cell);

    while (true){

        //* Step 1 -- Get player action
        generatePlayerAction(cell);             // TODO1: Complete this function
        
        //* Step 2 -- Update the map with player's action
        std::cout << "\nYour Move: \n";
        printMap(cell);

        //* Step 3 -- Check if player has won
        if (checkVictory(cell)) {               // TODO2: Complete this function
            std::cout << "Player has won";
            break;
        }

        //* Step 4 -- If Step 3 was not true, check if the board is filled
        // Note: Since we would've ended the game earlier if player has won, 
        //       if all the grids have been filled now, it means that the game is a tie.
        if (checkBoardFilled(cell)) {           // TODO3: Complete this function
            std::cout << "Game is TIED \n";
            break;
        }
        
        //* Step 5 -- Generate opponent's actions
        generateOpponentAction(cell);           // TODO4: Complete this function

        //* Step 6 -- Update the map with opponent's action
        std::cout << "Opponent's Move: \n";
        printMap(cell);
        
        //* Step 7 -- Check if opponent has won
        if (checkVictory(cell)) {               // TODO2: Complete this function (This is the same as step 3)
            std::cout << "Opponent has won \n";
            break;
        }
    }
}