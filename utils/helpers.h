#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <limits>
using namespace std;

// Clear the console (works on Windows)
void clearScreen() {
    system("cls");
}

// Pause until user presses Enter
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

#endif
