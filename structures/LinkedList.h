#ifndef CONTACT_H
#define CONTACT_H

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

void displayContacts() {
    if (head == NULL) {
        cout << "No contacts available.\n";
        return;
    }

    Contact *temp = head;

    while (temp != NULL) {
        cout << "Name  : " << temp->name << endl;
        cout << "Phone : " << temp->phone << endl;
        cout << "Email : " << temp->email << endl;
        cout << "-------------------\n";
        temp = temp->next;
    }
}

void searchContact() {
    char searchName[50];
    cout << "Enter name to search: ";
    cin.ignore();
    cin.getline(searchName, 50);

    Contact *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, searchName) == 0) {
            cout << "Contact Found:\n";
            cout << "Name  : " << temp->name << endl;
            cout << "Phone : " << temp->phone << endl;
            cout << "Email : " << temp->email << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Contact not found.\n";
}

void updateContact() {
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

void deleteContact() {
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

#endif
