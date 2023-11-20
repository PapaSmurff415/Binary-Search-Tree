#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor for Node and initializing value
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* insertTree(Node* root, int x);
    Node* searchParent(Node* root, int x);
    Node* searchTree(Node* root, int x);
    Node* deleteNode(Node* root, int x); // Updated return type
    void destroyTree(Node* root);
    void preorderTraversal(Node* root);
    void inorderTraversal(Node* root);
    void postorderTraversal(Node* root);

public:
    Node* root;

    // Constructor to initialize root to zero
    BinaryTree() : root(nullptr) {}

    // Destructor to free memory
    ~BinaryTree() {
        destroyTree(root);
    }
    // Wrapper function for deleteNode
    void deleteNode(int x) {
        root = deleteNode(root, x);
    }

    // Wrapper function for searchTree
    void searchAndDisplayTree(int x) {
        Node* foundNode = searchTree(root, x);
        if (foundNode) {
            cout << "Tree rooted at node " << x << " found:\n";

            cout << "Preorder Traversal: ";
            preorderTraversal(foundNode);

            cout << "\nInorder Traversal: ";
            inorderTraversal(foundNode);

            cout << "\nPostorder Traversal: ";
            postorderTraversal(foundNode);
        } 
        else {
            cout << "Node " << x << " not found in the tree.\n";
        }
    }
};

int main() {
    BinaryTree B; // creating object
    int x;

    cout << "Enter numbers to build the tree (enter -99 to stop):" << endl;
    cin >> x;

    while (x != -99) {
        // calling with the help of object
        B.root = B.insertTree(B.root, x);
        cin >> x;
    }

    cout << "\nPreorder Traversal: ";
    B.preorderTraversal(B.root);

    cout << "\nInorder Traversal: ";
    B.inorderTraversal(B.root);

    cout << "\nPostorder Traversal: ";
    B.postorderTraversal(B.root);

    cout << "\nEnter a number to find its parent in the tree: ";
    cin >> x;

    Node* parent = B.searchParent(B.root, x);
    if (parent)
        cout << "Parent of " << x << " is the node containing: " << parent->data << endl;
    else
        cout << "Node " << x << " is the root of the tree or not found." << endl;

    cout << "Enter a number to be deleted from the tree: ";
    cin >> x;

    B.deleteNode(x);

    cout << "After deletion of " << x << " from the current BST:\n";

    cout << "Preorder Traversal: ";
    B.preorderTraversal(B.root);

    cout << "\nInorder Traversal: ";
    B.inorderTraversal(B.root);

    cout << "\nPostorder Traversal: ";
    B.postorderTraversal(B.root);

    cout << "\nEnter a number to search for the subtree: ";
    cin >> x;

    B.searchAndDisplayTree(x);

    return 0;
}

Node* BinaryTree::insertTree(Node* root, int x) {
    if (root == nullptr) {
        return new Node(x);
    }

    if (x < root->data) {
        root->left = insertTree(root->left, x);
    } else {
        root->right = insertTree(root->right, x);
    }

    return root;
}

Node* BinaryTree::searchParent(Node* root, int x) {
    if (root == nullptr || (root->left && root->left->data == x) || (root->right && root->right->data == x)) {
        return root;
    }

    if (x < root->data) {
        return searchParent(root->left, x);
    } else {
        return searchParent(root->right, x);
    }
}

Node* BinaryTree::searchTree(Node* root, int x) {
    if (root == nullptr || root->data == x) {
        return root;
    }

    if (x < root->data) {
        return searchTree(root->left, x);
    } else {
        return searchTree(root->right, x);
    }
}

Node* BinaryTree::deleteNode(Node* root, int x) {
    // Base case: if the tree is empty
    if (root == nullptr) {
        cout << "Node with data " << x << " not found in the tree." << endl;
        return root;
    }

    // Find the node to delete
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: get the in-order successor (smallest in the right subtree)
        Node* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copy the in-order successor's data to this node
        root->data = successor->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

void BinaryTree::destroyTree(Node* root) {
    if (root) {
        destroyTree(root->left);
        destroyTree(root->right);
        cout << "\nFreeing up node " << root->data << endl;
        delete root;
    }
}

void BinaryTree::preorderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void BinaryTree::inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void BinaryTree::postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}
