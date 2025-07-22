// ID : 22011261
// Name : Lee Pei Lin
// Lab : Lab 8 BST

#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;

    Node(string n)
    {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        root = nullptr;
    }

    void insert(string name)
    {
        if (!root)
        {
            root = new Node(name);
            return;
        }
        insert_recursive(root, name);
    }

private:
    void insert_recursive(Node* current, string name)
    {
        if (name < current->name)
        {
            if (!current->left)
            {
                current->left = new Node(name);
            }
            else
            {
                insert_recursive(current->left, name);
            }
        }
        else
        {
            if (!current->right)
            {
                current->right = new Node(name);
            }
            else
            {
                insert_recursive(current->right, name);
            }
        }
    }

public:
    void display(Node *node)
    {
        if (!node)
            return;
        display(node->left);
        cout << " " << node->name;
        display(node->right);
    }
};

int main()
{
    BinarySearchTree bst;

    // Insert nodes in a way that maintains BST property
    string names[] = {"E", "B", "G", "A", "D", "F", "C"};
    for (const string& name : names)
    {
        bst.insert(name);
    }

    bst.display(bst.root);

    return 0;
} 