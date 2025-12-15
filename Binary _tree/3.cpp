#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

/*
POSTORDER TRAVERSAL
Rule: Left → Right → Root

For each node:
1. Visit left subtree
2. Visit right subtree
3. Process (print) the node
*/
void postorder(Node* root) {
    // Base case: if tree is empty
    if (root == nullptr)
        return;

    // Step 1: Traverse left subtree
    postorder(root->left);

    // Step 2: Traverse right subtree
    postorder(root->right);

    // Step 3: Visit root node
    cout << root->data << " ";
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call postorder traversal
    postorder(root);

    return 0;
}
