#include<bits/stdc++.h>
using namespace std;

class Node {   //preoder root-left -right
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Preorder Traversal
void preorder(Node* root, vector<int>& result) {
    if (root == nullptr) return;

    result.push_back(root->data);     // Root
    preorder(root->left, result);     // Left
    preorder(root->right, result);    // Right
}

int main() {
    // Creating tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;
    preorder(root, ans);

    // Printing preorder traversal
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
