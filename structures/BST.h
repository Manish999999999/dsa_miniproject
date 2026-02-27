#ifndef BST_H
#define BST_H

#include "Contact.h"
#include <cstring>

struct TreeNode {
    Contact data;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;

    void insert(TreeNode*& node, Contact c) {
        if (node == NULL) {
            node = new TreeNode;
            node->data = c;
            node->left = node->right = NULL;
        } else if (strcmp(c.name, node->data.name) < 0) {
            insert(node->left, c);
        } else {
            insert(node->right, c);
        }
    }

    TreeNode* search(TreeNode* node, const char* name) {
        if (node == NULL) return NULL;
        int cmp = strcmp(name, node->data.name);
        if (cmp == 0) return node;
        else if (cmp < 0) return search(node->left, name);
        else return search(node->right, name);
    }

public:
    BST() { root = NULL; }

    void addContact(Contact c) {
        insert(root, c);
    }

    TreeNode* findContact(const char* name) {
        return search(root, name);
    }

    // In-order traversal (for display)
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << "Name  : " << node->data.name << endl;
            cout << "Phone : " << node->data.phone << endl;
            cout << "Email : " << node->data.email << endl;
            cout << "-------------------\n";
            inorder(node->right);
        }
    }

    void displayAll() {
        if (root == NULL)
            cout << "No contacts.\n";
        else
            inorder(root);
    }
};

#endif
