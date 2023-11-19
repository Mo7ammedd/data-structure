#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    bool searchRecursive(Node* current, int value) const {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // Helper function for in-order traversal
    void inOrderTraversal(Node* current) const {
        if (current != nullptr) {
            inOrderTraversal(current->left);
             cout << current->data << " ";
            inOrderTraversal(current->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) const {
        return searchRecursive(root, value);
    }

    void inOrderTraversal() const {
         cout << "In-order traversal: ";
        inOrderTraversal(root);
         cout <<  endl;
    }
};

int main() {
    BinaryTree myTree;

    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(70);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(60);
    myTree.insert(80);

    myTree.inOrderTraversal();

    int valueToSearch = 40;
    if (myTree.search(valueToSearch)) {
         cout << valueToSearch << " found in the tree." <<  endl;
    } else {
         cout << valueToSearch << " not found in the tree." <<  endl;
    }

    return 0;
}
