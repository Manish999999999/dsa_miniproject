#include <iostream>
#include "structures/Contact.h"
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
