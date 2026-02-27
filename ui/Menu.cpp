#include "Menu.h"
#include <iostream>
using namespace std;

void showMainMenu() {
    cout << "\n=====================================\n";
    cout << "   CONTACT MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "1. Add Contact\n";
    cout << "2. Display All Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Update Contact\n";
    cout << "5. Delete Contact\n";
    cout << "6. View Recent Contacts\n";
    cout << "7. Show Undo Stack\n";
    cout << "8. Exit\n";
    cout << "Enter choice: ";
}

int getUserChoice() {
    int ch;
    cin >> ch;
    return ch;
}
