// main.cpp – Contact Management System with multiple DS
#include <iostream>
#include <cstring>
#include "structures/Contact.h"
#include "structures/LinkedList.h"
#include "structures/Stack.h"
#include "structures/Queue.h"
#include "ui/Menu.h"
#include "utils/helpers.h"

using namespace std;

// Global instances (for simplicity)
LinkedList contactList;
Stack undoStack;
Queue recentQueue;

// Helper to input contact details
Contact inputContact() {
    Contact c;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(c.name, 50);
    cout << "Enter Phone: ";
    cin.getline(c.phone, 15);
    cout << "Enter Email: ";
    cin.getline(c.email, 50);
    return c;
}

int main() {
    int choice;
    do {
        clearScreen();
        showMainMenu();
        choice = getUserChoice();

        switch (choice) {
            case 1: {   // Add Contact
                Contact c = inputContact();
                contactList.addContact(c);
                // Push to undo stack
                char action[100] = "Added ";
                strcat(action, c.name);
                undoStack.push(action);
                // Also add to recent queue
                recentQueue.enqueue(c.name);
                pause();
                break;
            }
            case 2: {   // Display All
                clearScreen();
                cout << "--- ALL CONTACTS ---\n";
                contactList.displayAll();
                pause();
                break;
            }
            case 3: {   // Search Contact
                char name[50];
                cout << "Enter name to search: ";
                cin.ignore();
                cin.getline(name, 50);
                Node* node = contactList.searchByName(name);
                if (node) {
                    cout << "Contact found:\n";
                    cout << "Name  : " << node->data.name << endl;
                    cout << "Phone : " << node->data.phone << endl;
                    cout << "Email : " << node->data.email << endl;
                    // Add to recent queue
                    recentQueue.enqueue(name);
                } else {
                    cout << "Contact not found.\n";
                }
                pause();
                break;
            }
            case 4: {   // Update Contact
                char name[50];
                cout << "Enter name to update: ";
                cin.ignore();
                cin.getline(name, 50);
                Node* node = contactList.searchByName(name);
                if (node) {
                    cout << "Enter new phone: ";
                    cin.getline(node->data.phone, 15);
                    cout << "Enter new email: ";
                    cin.getline(node->data.email, 50);
                    cout << "Contact updated.\n";
                    char action[100] = "Updated ";
                    strcat(action, name);
                    undoStack.push(action);
                    recentQueue.enqueue(name);
                } else {
                    cout << "Contact not found.\n";
                }
                pause();
                break;
            }
            case 5: {   // Delete Contact
                char name[50];
                cout << "Enter name to delete: ";
                cin.ignore();
                cin.getline(name, 50);
                if (contactList.deleteByName(name)) {
                    cout << "Contact deleted.\n";
                    char action[100] = "Deleted ";
                    strcat(action, name);
                    undoStack.push(action);
                } else {
                    cout << "Contact not found.\n";
                }
                pause();
                break;
            }
            case 6: {   // View Recent Contacts
                clearScreen();
                cout << "--- RECENT CONTACTS ---\n";
                recentQueue.displayRecent();
                pause();
                break;
            }
            case 7: {   // Show Undo Stack
                clearScreen();
                cout << "--- UNDO STACK ---\n";
                undoStack.display();
                pause();
                break;
            }
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
                pause();
        }
    } while (choice != 8);

    return 0;
}
