/* 
*   Project -- Snake Game [Advanced]

    ? Learning Objectives
    1. Challenge yourself!

    ! Important Tips
    1. Consider following the recommended order of TODO

    ? More challenges
    1. Add a 4x4 obstacle at the middle of the map. Food should not be generated there.
    2. Add a wrap-around function for the walls (i.e. enter right wall, emerge left wall)
    3. Add a 'poison' that reduces length by half (while respecting minimum = 1)
*/

#include <iostream>
#include "snake.h"

#define H 20
#define W 20

#if __linux__
    #define TIMESTEP 150000    // Initialize timestep in microseconds
#endif

#if WIN32
    #define TIMESTEP 100       // Initialize timestep in milliseconds
#endif

#define ADVANCED 1             // Toggle ADVANCED mode (0 for default, 1 for More Challenges)

/**
 * Print map on console screen row-by-row.
 * 
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @param  posHead  - coordinates of snake's head position
 * @return void
 */
void render(int map[H][W], int posHead[2]) {

    /* 1st row */
    for (int j = 0; j < W + 2; j++) std::cout << "# "; // Print top wall
    std::cout << "\n"; // line break;
    
    /* 2nd row to (H+1) rows */
    for (int i = 0; i < H; i++) { 
        
        std::cout << "# "; // Print left wall
        
        for (int j = 0; j < W; j++) {

            // std::cout << map[i][j] << " "; // Print number map. Comment this out if printing the appropriate characters instead.
            
            // TODO1: Instead of printing the number map above, convert the numbers and print the appropriate characters (approx ~5 lines of code)
            // 0: Empty square ' '
            // -1: Food '$'
            // +ve (but not snake head): '*'
            // +ve (snake head): '@'
            // Remember to comment out the above number map
            if (map[i][j] == 0) std::cout << "  ";
            else if (map[i][j] == -1) std::cout << "$ ";
            else if (map[i][j] == -2) std::cout << "X ";
            else if (map[i][j] == -9) std::cout << "# ";
            else if (i == posHead[0] && j == posHead[1]) std::cout << "@ "; // Print head position differently
            else std::cout << "* ";

        }

        std::cout << "#\n"; // Print right wall and line break
    }

    /* Last row */
    for (int j = 0; j < W + 2; j++) std::cout << "# "; // Print bottom wall
    std::cout << "\nLength = "<< map[posHead[0]][posHead[1]];
    std::cout << "\n"; // line break;
}

/**
 * Update position of snake's head from commanded direction
 *
 * @param  posHead  - coordinates of snake's head position
 * @param  dir      - 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
 * @return void
 */
void updateHeadPosition(int posHead[2], int dir) {
    // TODO2: Update position of head based on the value of dir  (~4 lines of code)
    if (dir == 0) posHead[0] -= 1;
    else if (dir == 1) posHead[0] += 1;
    else if (dir == 2) posHead[1] -= 1;
    else if (dir == 3) posHead[1] += 1;
}

/**
 * Extend length of snake by updating the map with its new head position.
 * The final length of snake = current length + 1.
 *
 * @param  posHeadNew - coordinates of snake's head new position
 * @return void
 */
void extendSnake(int map[H][W], int posHeadNew[2], int length) {
    // TODO3: Assign the value of length + 1 to the position of the new head  (~1-3 line of code)
    map[posHeadNew[0]][posHeadNew[1]] = length + 1;

}

/**
 * Reduce length of snake by 1 by subtracting 1 from all +ve squares in map
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @return void
 */
void reduceSnake(int map[H][W]) {
    // TODO4: Minus one from all +ve squares in the map (~5 lines of code)
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] > 0) {
                map[i][j] -= 1;
            }
        }
    }
}

/**
 * Generate random XY coordinates for food on an empty square on the map and name it -1
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @param  posFood  - coordinates of food position
 * @return void
 */
void generateFood(int map[H][W], int posFood[2])
{
    // TODO5: Generate a random XY coordinate for food within the map (~5 lines of code)
    // You should keep generating a XY coordinate until you get a valid solution (i.e. food should only appear on empty square)
    do
    {
        posFood[0] = rand() % H;
        posFood[1] = rand() % W;
    } while (map[posFood[0]][posFood[1]] != 0);

    // Modify map with food's position and value
    map[posFood[0]][posFood[1]] = -1;
}

// TODO (ADVANCED)
/**
 * Generate random XY coordinates for poison on an empty square on the map.
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
 * @param  posPoison  - coordinates of poison position
 * @return void
 */
void generatePoison(int map[H][W], int posPoison[2])
{
    // Generate a random XY coordinate for poison
    do
    {
        posPoison[0] = rand() % H;
        posPoison[1] = rand() % W;
    } while (map[posPoison[0]][posPoison[1]] != 0);

    // Modify map with poisons's position and value
    map[posPoison[0]][posPoison[1]] = -2;
}

/**
 * Check if snake head and food has collided.
 *
 * @param  posHead  - coordinates of snake's head position
 * @param  posFood  - coordinates of food position
 * @return bool     - True if both X and Y values are equal
 */
bool isCollisionFood(int posHead[2], int posFood[2]) {
    // TODO6: Return true if collision has occured (~1-3 line of code)
    return (posHead[0] == posFood[0] && posHead[1] == posFood[1]);
    return false; 
}

// TODO (ADVANCED)
/**
 * Check if snake head and obstacle has collided.
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
 * @return bool     - True if both X and Y coordinates of head reaches a -9 square.
 */
bool isCollisionObstacle(int map[H][W], int posHead[2]) {
    return (map[posHead[0]][posHead[1]] == -9);
}

/**
 * Update snake's growth / movement
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
   @param  posFood  - coordinates of food's position
   @param  posPoison- coordinates of poision's position (Advanced)
   @param  length   - current length of snake
 * @return void
 */
void update(int map[H][W], int posHead[2], int posFood[2], int posPoison[2], int length) {

    // TODO7: Check if food has been 'eaten' by the snake. (~8 lines of code)
    if (isCollisionFood(posHead, posFood)) {

        // TODO7: If food is eaten, call the (completed) functions to extend snake and regenerate food
        extendSnake(map, posHead, length);
        generateFood(map, posFood);

        if (ADVANCED){
	        map[posPoison[0]][posPoison[1]] = 0;
        	generatePoison(map, posPoison);
        }
    }

    else if (ADVANCED && isCollisionFood(posHead, posPoison)) {
        extendSnake(map, posHead, length);
        reduceSnake(map);
        generatePoison(map, posPoison);
        for (int i = 0; i < length / 2; i++) reduceSnake(map);

        if (ADVANCED){
	        map[posFood[0]][posFood[1]] = 0;
	        generateFood(map, posFood);
	    }
    }

    else {
        // Else, move the snake by extending snake and reducing snake. Call the (completed) functions that will cause it to move
        // If the below functions (and updateHeadPosition) are implemented correctly, you should be able to move the snake
        extendSnake(map, posHead, length);
        reduceSnake(map);
    }
}

/**
 * Check if snake head and walls has collided.
 *
 * @param  posHead  - coordinates of snake's head position
 * @return bool     - True if either X or Y position of head reaches wall coordinates.
 */
bool isCollisionWall(int posHead[2]) {
    // TODO8: Return true if collision has occured (~1-3 line of code)
     return (posHead[0] < 0 || posHead[0] >= H || posHead[1] < 0 || posHead[1] >= W);
}

/**
 * Check if snake head and body has collided.
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
 * @return bool     - True if both X and Y coordinates of head reaches a +ve square.
 */
bool isCollisionSelf(int map[H][W], int posHead[2]) {
    // TODO8: Return true if collision has occured (~1-3 line of code)
    return (map[posHead[0]][posHead[1]] > 0);
}

/**
 * Initialize snake's position, printing leftwards from posHead.
 *
 * @param  map      - integer array containing information of empty squares, snake and food positions.
   @param  posHead  - coordinates of snake's head position
   @param  length   - current length of snake
 * @return void
 */
void initializeSnake(int map[H][W], int posHead[2], int length) {
    for (int i = 0; i < length; i++) {
        map[0][posHead[1] - i] = length - i;
    }
}

int main() {

    srand(time(0));              // Initialize a random seed

    int map[H][W] = {};          // Playable map. 0: Empty square. +ve: Snake position, -ve: Food position.
    int direction = 3;           // Command direction, obtained from user input. 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    double prevTime = clock();   // Record of clock from previous cycle to ensure 
    
    int length = 3;              // Current length of snake
    int posHead[2] = { 0, 4 };   // Current position of snake's head
    int posFood[2] = { 0, 0 };   // Current position of food
    int posPoison[2] = { 0, 0 }; // Current position of poison (Advanced)

    // Initialize snake and food position on map
    initializeSnake(map, posHead, length);

    // Obstacles (Advanced)
    if (ADVANCED){
        for (int i = 8; i < 12; i++) {
            for (int j = 8; j < 12; j++) {
                map[i][j] = -9;
            }
       }
       generatePoison(map, posPoison);
    }

    generateFood(map, posFood);

    while (1) {

        // Refresh console display
        clearScreen();
        render(map, posHead);
        std::cout << "Direction received = " << direction << "\n";

        // Hold program in this loop until timestep of loop passed or key pressed
        while (!isTimeElapsed(prevTime, TIMESTEP) && !isKeyPressed()); 

        // Get commanded direction
        if (isKeyPressed()) direction = getKeyDirection();

        // Update position of snake's head with commanded direction
        updateHeadPosition(posHead, direction); // TODO: Fill in this function!

        // TODO9: Check for collisions with walls and body.
        // If collision has occured, print "Game Over" and exit while loop.  (~3 lines of code)
        if (isCollisionWall(posHead) || isCollisionSelf(map, posHead) || isCollisionObstacle(map, posHead)) 
        {
            if (ADVANCED && isCollisionWall(posHead)) { // Wrap around wall (Advanced)
                posHead[0] = (posHead[0] + H) % H;
                posHead[1] = (posHead[1] + W) % W;
            }
            
            else {
                printf("Game over");
                break;
            }
        }

        // Update map
        update(map, posHead, posFood, posPoison, length);

        // Update length of snake and previous cycle timestamp
        length = map[posHead[0]][posHead[1]];
        prevTime = clock();
    }

    return 0;
}
