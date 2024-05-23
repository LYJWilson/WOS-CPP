
#if __linux__
    #include <ncurses.h>
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>

    // These utility functions do not need to be modified

    /**
    * Function to check if key is hit
    * 
    * @return true if key is pressed
    */
    bool isKeyPressed()
    {
      struct termios oldt, newt;
      int ch;
      int oldf;
    
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
      ch = getchar();
    
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);
    
      if(ch != EOF)
      {
        ungetc(ch, stdin);
        return true;
      }
    
      return false;
    }

    /**
    * Get commanded direction from console input using standard library functions.
    *
    * @param  void
    * @return dir    - 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    */
    int getKeyDirection() {

        int dir = 0;

        // Series of commands necessary to extract arrow keys
        getchar();
        getchar();
        int tmp = getchar(); 

        // (Linux) Map the default getchar() values to our preferred values
        if (tmp == 65) dir = 0;
        if (tmp == 66) dir = 1;
        if (tmp == 68) dir = 2;
        if (tmp == 67) dir = 3;

        return dir;
    }

    void clearScreen(){
      system("clear");
    }
#endif

#if WIN32
    #include <stdio.h>
    #include <conio.h>
    #include <time.h>
    #include <Windows.h>
    
    /**
    * Function to check if key is hit
    * 
    * @return true if key is pressed
    */
    bool isKeyPressed() {
        return _kbhit();
    }

    /**
    * Get commanded direction from console input using standard library functions.
    *
    * @param  void
    * @return dir    - 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    */
    int getKeyDirection() {

        int dir = 0;

        _getch();
        int tmp = _getch(); 

        // Map the default _getch() values to our preferred values
        if (tmp == 72) dir = 0;
        if (tmp == 80) dir = 1;
        if (tmp == 75) dir = 2;
        if (tmp == 77) dir = 3;

        return dir;
    }
    
    void hideCursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
    }

    void clearScreen()
    {
        hideCursor();
        HANDLE                     hStdOut;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD                      count;
        DWORD                      cellCount;
        COORD                      homeCoords = { 0, 0 };

        hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdOut == INVALID_HANDLE_VALUE) return;

        /* Get the number of cells in the current buffer */
        if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        /* Fill the entire buffer with spaces */
        if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR)' ',
            cellCount,
            homeCoords,
            &count
        )) return;

        /* Fill the entire buffer with the current colors and attributes */
        if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count
        )) return;

        /* Move the cursor home */
        SetConsoleCursorPosition(hStdOut, homeCoords);
    }

#endif

/**
 * Check if timestep has passed since the previous time stamp.
 *
 * @param  prevTime - Previous time stamp.
 * @return bool     - True if timestep has passed, if not, return False.
 */
bool isTimeElapsed(double prevTime, double timestep) {

    if (clock() - prevTime <= timestep) {
        return false;
    }

    else {
        return true;
    }
}
