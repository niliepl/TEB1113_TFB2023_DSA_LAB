// ID : 22011261
// Name : Lee Pei Lin
// Lab : Lab 7 Binary Tree 

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string data) {
        root = new Node(data);
    }

    void add_left(Node* parent, string data) {
        parent->left = new Node(data);
    }

    void add_right(Node* parent, string data) {
        parent->right = new Node(data);
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left(tree.root, "B");
    tree.add_right(tree.root, "C");
    tree.add_left(tree.root->left, "D");
    tree.add_right(tree.root->left, "E");
    tree.add_left(tree.root->right, "F");
    tree.add_right(tree.root->right, "G");

    cout << "Root: " << tree.root->data << endl;
    cout << "Left child of root: " << tree.root->left->data << endl;
    cout << "Right child of root: " << tree.root->right->data << endl;
    cout << "Left child of B: " << tree.root->left->left->data << endl;
    cout << "Right child of B: " << tree.root->left->right->data << endl;
    cout << "Left child of C: " << tree.root->right->left->data << endl;
    cout << "Right child of C: " << tree.root->right->right->data << endl;

    return 0;
}
