#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_UNDO 5

// Simple stack to store last few actions
class Stack {
private:
    char* arr[MAX_UNDO];   // array of C‑strings
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push an action description
    bool push(const char* action) {
        if (top >= MAX_UNDO - 1) {
            // shift: remove oldest, make room
            delete[] arr[0];
            for (int i = 0; i < top; i++)
                arr[i] = arr[i+1];
            arr[top] = new char[strlen(action)+1];
            strcpy(arr[top], action);
            return true;
        }
        top++;
        arr[top] = new char[strlen(action)+1];
        strcpy(arr[top], action);
        return true;
    }

    // Pop last action (return by reference)
    bool pop(char*& action) {
        if (top < 0)
            return false;
        action = arr[top];
        top--;
        return true;
    }

    // Display undo stack
    void display() {
        if (top < 0) {
            cout << "No actions to undo.\n";
            return;
        }
        cout << "Last actions (most recent first):\n";
        for (int i = top; i >= 0; i--) {
            cout << "  " << arr[i] << endl;
        }
    }

    // Destructor
    ~Stack() {
        for (int i = 0; i <= top; i++)
            delete[] arr[i];
    }
};

#endif
