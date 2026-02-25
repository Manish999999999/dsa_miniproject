#include <iostream>
#include <cstring>
using namespace std;

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    Contact *next;
};

Contact *head = NULL;

// Function to add a new contact
void addContact() {
    Contact *newNode = new Contact;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(newNode->name, 50);

    cout << "Enter Phone: ";
    cin.getline(newNode->phone, 15);

    cout << "Enter Email: ";
    cin.getline(newNode->email, 50);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Contact *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Contact added successfully.\n";
}

// Function to display all contacts
void displayContacts() {
    if (head == NULL) {
        cout << "No contacts available.\n";
        return;
    }

    Contact *temp = head;
    cout << "\nContact List:\n";

    while (temp != NULL) {
        cout << "Name  : " << temp->name << endl;
        cout << "Phone : " << temp->phone << endl;
        cout << "Email : " << temp->email << endl;
        cout << "----------------------\n";
        temp = temp->next;
    }
}

// Function to search a contact
void searchContact() {
    if (head == NULL) {
        cout << "No contacts to search.\n";
        return;
    }

    char searchName[50];
    cout << "Enter name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);

    Contact *temp = head;
    bool found = false;

    while (temp != NULL) {
        if (strcmp(temp->name, searchName) == 0) {
            cout << "Contact Found:\n";
            cout << "Name  : " << temp->name << endl;
            cout << "Phone : " << temp->phone << endl;
            cout << "Email : " << temp->email << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Contact not found.\n";
    }
}

// Function to delete a contact
void deleteContact() {
    if (head == NULL) {
        cout << "No contacts to delete.\n";
        return;
    }

    char deleteName[50];
    cout << "Enter name to delete: ";
    cin.ignore();
    cin.getline(deleteName, 50);

    Contact *temp = head;
    Contact *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, deleteName) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Contact deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Contact not found.\n";
}

// Function to update a contact
void updateContact() {
    if (head == NULL) {
        cout << "No contacts to update.\n";
        return;
    }

    char updateName[50];
    cout << "Enter name to update: ";
    cin.ignore();
    cin.getline(updateName, 50);

    Contact *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, updateName) == 0) {
            cout << "Enter new phone: ";
            cin.getline(temp->phone, 15);

            cout << "Enter new email: ";
            cin.getline(temp->email, 50);

            cout << "Contact updated successfully.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Contact not found.\n";
}

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
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
