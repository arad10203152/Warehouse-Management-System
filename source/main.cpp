// source/main.cpp
#include <iostream>
#include <string>
#include <limits> 
#include "../include/Warehouse.h"
#include "../include/Product.h"
#include "../include/PerishableProduct.h"
#include "../include/TerminalUtils.h"

using namespace std;

// A robust function to completely clear the input buffer and reset flags
void clearInputBuffer() {
    cin.clear(); // Clear error flags if cin failed
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad data until Enter
}

int main() {
    Warehouse warehouse; // Automatically loads existing data from inventory.json
    int selectedOption = 1;
    
    // Fetch clean ANSI styles from our utility for Linux/Mac terminal
    string HIGHLIGHT = getNormalHighlight();
    string RED_HIGHLIGHT = getRedHighlight();
    string RESET = getResetColor();

    while (true) {
        clearScreen(); // Clears terminal screen and resets cursor position

        cout << "=================================\n";
        cout << "   Warehouse Management System   \n";
        cout << "=================================\n\n";
        
        if (selectedOption == 1) cout << HIGHLIGHT << " > [1] Add Normal Product " << RESET << "\n";
        else cout << "   [1] Add Normal Product\n";
        
        if (selectedOption == 2) cout << HIGHLIGHT << " > [2] Add Perishable Product " << RESET << "\n";
        else cout << "   [2] Add Perishable Product\n";
        
        if (selectedOption == 3) cout << HIGHLIGHT << " > [3] Show Inventory " << RESET << "\n";
        else cout << "   [3] Show Inventory\n";
        
        if (selectedOption == 4) cout << RED_HIGHLIGHT << " > [4] Exit " << RESET << "\n";
        else cout << "   [4] Exit\n";

        cout << "\n---------------------------------\n";
        cout << "Use Arrow Keys to move and press Enter.\n";

        // Handle inputs based on clean enum actions instead of raw numbers
        MenuAction action = handleInput();

        if (action == UP) {
            selectedOption--;
            if (selectedOption < 1) selectedOption = 4;
        }
        else if (action == DOWN) {
            selectedOption++;
            if (selectedOption > 4) selectedOption = 1;
        }
        else if (action == ENTER) {
            if (selectedOption == 4) {
                cout << "\nExiting and saving data...\n";
                break;
            }
            
            // Option 1: Add Normal Product
            if (selectedOption == 1) {
                int id, qty; string name; double price;
                
                // Safe ID Input Loop
                while (true) {
                    cout << "\nEnter ID (Numbers only): ";
                    if (cin >> id) {
                        break; // Input is valid, break loop
                    } else {
                        cout << "❌ Invalid input! Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                cout << "Enter Name: "; 
                cin >> name;

                // Safe Price Input Loop
                while (true) {
                    cout << "Enter Price: ";
                    if (cin >> price) {
                        break;
                    } else {
                        cout << "❌ Invalid price! Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Safe Quantity Input Loop
                while (true) {
                    cout << "Enter Quantity: ";
                    if (cin >> qty) {
                        break;
                    } else {
                        cout << "❌ Invalid quantity! Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                
                clearInputBuffer(); // Clean the buffer trailing enter key
                
                warehouse.addProduct(new Product(id, name, price, qty));
                cout << "\n✅ Product added! Press any key to return...";
                getKeyPress();
            }
            // Option 2: Add Perishable Product
            else if (selectedOption == 2) {
                int id, qty; string name; double price; string date;
                
                // Safe ID Input Loop
                while (true) {
                    cout << "\nEnter ID (Numbers only): ";
                    if (cin >> id) {
                        break;
                    } else {
                        cout << "❌ Invalid input! Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                cout << "Enter Name: "; 
                cin >> name;

                // Safe Price Input Loop
                while (true) {
                    cout << "Enter Price: ";
                    if (cin >> price) {
                        break;
                    } else {
                        cout << "❌ Invalid price! Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Safe Quantity Input Loop
                while (true) {
                    cout << "Enter Quantity: ";
                    if (cin >> qty) {
                        break;
                    } else {
                        cout << "❌ Invalid quantity! Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                cout << "Enter Expiry Date (YYYY-MM-DD): "; 
                cin >> date;
                
                clearInputBuffer(); // Clean the buffer trailing enter key
                
                warehouse.addProduct(new PerishableProduct(id, name, price, qty, date));
                cout << "\n✅ Perishable Product added! Press any key to return...";
                getKeyPress();
            }
            // Option 3: Show Inventory
            else if (selectedOption == 3) {
                cout << "\n--- Current Inventory ---\n";
                warehouse.showInventory();
                cout << "\nPress any key to return...";
                getKeyPress();
                clearInputBuffer(); 
            }
        }
    }
    return 0;
}