 Contact Management System

A console-based C++ project to manage contacts using multiple data structures – Linked List, Stack, and Queue.  
Built for learning Data Structures & Algorithms in a practical way.

---------------------------------------------------------------------------------------------

# Overview

This program lets you store, view, search, update, and delete contacts.  
It also demonstrates:

- **Undo functionality** using a Stack (stores last 5 actions).
- **Recently viewed contacts** using a Queue.
- *(Optional)* **Binary Search Tree** for faster search by name.

All operations are menu-driven and user-friendly.

---------------------------------------------------------------------------------------------

# Features

- Add new contact
- Display all contacts
- Search contact by name
- Update contact details
- Delete contact
- View last 5 recently viewed contacts
- Show undo stack (last 5 actions)
- Menu-driven interface

---------------------------------------------------------------------------------------------

## Data Structures Used

### 1. Singly Linked List
   - Stores all contacts.
   - Each node contains: name, phone, email, and pointer to next.

### 2. Stack (Array-based)
   - Remembers the last 5 actions (add, update, delete) for potential undo.
   - Implements LIFO principle.

### 3. Queue (Circular Array)
   - Tracks the last 5 viewed contacts (by search or update).
   - Implements FIFO principle.

### 4. Binary Search Tree (Optional)
   - Can be enabled for faster search by name.
   - Stores contacts in sorted order.

---------------------------------------------------------------------------------------------

## Build Instructions

### Requirements
- C++ compiler (supports C++17 or later)
- Any IDE / terminal (VS Code, Code::Blocks, or command line)

### Compilation Command
```bash
g++ main.cpp ui/Menu.cpp -o contact
If you include BST, add structures/BST.h (no extra .cpp needed for headers).

Run the Program
bash
./contact          # Linux/Mac
contact.exe        # Windows
Technologies Used
C++ Programming Language

Standard Template Library (only <iostream>, <cstring> – no STL containers used)

Manual memory management (new/delete)
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Author
Name: Manish Khatri
Roll Number: 25
Branch: Computer Engineering (II/I)
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
##Submitted To
Er. Sagar Acharya Sir
Department of Computer Engineering
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
License
This project is created for academic and learning purposes only.
It can be modified and used for educational use.
