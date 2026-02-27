#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;

// Node for linked list
struct Node {
    Contact data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Add contact at the end
    void addContact(Contact c) {
        Node* newNode = new Node;
        newNode->data = c;   // copy whole struct
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Contact added.\n";
    }

    // Display all contacts
    void displayAll() {
        if (head == NULL) {
            cout << "No contacts.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << "Name  : " << temp->data.name << endl;
            cout << "Phone : " << temp->data.phone << endl;
            cout << "Email : " << temp->data.email << endl;
            cout << "-------------------\n";
            temp = temp->next;
        }
    }

    // Search by name (returns pointer to node, or NULL)
    Node* searchByName(const char* name) {
        Node* temp = head;
        while (temp != NULL) {
            if (strcmp(temp->data.name, name) == 0)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    // Update contact (assumes node found)
    void updateContact(Node* node, const char* newPhone, const char* newEmail) {
        strcpy(node->data.phone, newPhone);
        strcpy(node->data.email, newEmail);
    }

    // Delete by name
    bool deleteByName(const char* name) {
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {
            if (strcmp(temp->data.name, name) == 0) {
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    // Get head (for traversal from outside)
    Node* getHead() { return head; }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
