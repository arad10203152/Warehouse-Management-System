// source/TerminalUtils.cpp
#include "../include/TerminalUtils.h"
#include <termios.h>
#include <unistd.h>
#include <iostream>

using namespace std;

char getKeyPress() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ~ICANON");
    if (read(0, &buf, 1) < 0) perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror ("tcsetattr ICANON");
    return (buf);
}

void clearScreen() {
    // Clears terminal screen and moves cursor to top-left natively
    cout << "\033[2J\033[H";
}

string getNormalHighlight() { return "\033[42m\033[30m"; } // Green BG
string getRedHighlight()    { return "\033[41m\033[37m"; } // Red BG
string getResetColor()      { return "\033[0m"; }          // Reset

MenuAction handleInput() {
    char ch = getKeyPress();
    
    if (ch == 10) { // Mac/Linux Enter key
        return ENTER;
    }
    else if (ch == 27) { // Arrow key sequence starts
        char next1 = getKeyPress();
        char next2 = getKeyPress();
        
        if (next1 == '[') {
            if (next2 == 'A') return UP;   // Up Arrow
            if (next2 == 'B') return DOWN; // Down Arrow
        }
    }
    return NONE;
}