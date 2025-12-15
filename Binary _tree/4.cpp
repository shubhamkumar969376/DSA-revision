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
LEVEL ORDER TRAVERSAL (Breadth First Search - BFS)

Rule:
- Traverse tree level by level
- Visit nodes from left to right at each level

Steps:
1. Use a queue
2. Push root into queue
3. While queue is not empty:
   - Take front node
   - Print it
   - Push its left child (if exists)
   - Push its right child (if exists)
*/
void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != nullptr)
            q.push(curr->left);

        if (curr->right != nullptr)
            q.push(curr->right);
    }
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

    // Call level order traversal
    levelOrder(root);

    return 0;
}
