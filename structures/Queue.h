#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_RECENT 5

class Queue {
private:
    char* arr[MAX_RECENT];
    int front, rear, count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Add a name to recent (circular queue)
    void enqueue(const char* name) {
        if (count == MAX_RECENT) {
            // remove oldest (front)
            delete[] arr[front];
            front = (front + 1) % MAX_RECENT;
            count--;
        }
        rear = (rear + 1) % MAX_RECENT;
        arr[rear] = new char[strlen(name)+1];
        strcpy(arr[rear], name);
        count++;
    }

    // Display recent contacts
    void displayRecent() {
        if (count == 0) {
            cout << "No recent contacts.\n";
            return;
        }
        cout << "Recently viewed:\n";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << "  " << arr[idx] << endl;
            idx = (idx + 1) % MAX_RECENT;
        }
    }

    ~Queue() {
        for (int i = 0; i < count; i++) {
            delete[] arr[(front + i) % MAX_RECENT];
        }
    }
};

#endif
