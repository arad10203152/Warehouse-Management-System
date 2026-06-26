// include/TerminalUtils.h
#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H

#include <string>

// Enum to represent menu movements and actions clearly
enum MenuAction {
    UP,
    DOWN,
    ENTER,
    NONE
};

// Reads a single keypress immediately
char getKeyPress();

// Clears the screen and resets the cursor position safely
void clearScreen();

// Returns appropriate ANSI sequence to color or reset the text
std::string getNormalHighlight();
std::string getRedHighlight();
std::string getResetColor();

// Captures arrow keys and enter, returning a clear action
MenuAction handleInput();

#endif