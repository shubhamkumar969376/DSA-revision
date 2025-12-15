   // zigzag traversal
   
   
   #include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);

    int level = 0;

    while (!q.empty()) {
        int n = q.size();
        vector<int> currLevel;

        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();

            currLevel.push_back(curr->val);

            if (curr->left != nullptr)
                q.push(curr->left);

            if (curr->right != nullptr)
                q.push(curr->right);
        }

        // Reverse on odd levels
        if (level % 2 == 1) {
            reverse(currLevel.begin(), currLevel.end());
        }

        ans.push_back(currLevel);
        level++;
    }

    return ans;
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print result
    for (auto level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
