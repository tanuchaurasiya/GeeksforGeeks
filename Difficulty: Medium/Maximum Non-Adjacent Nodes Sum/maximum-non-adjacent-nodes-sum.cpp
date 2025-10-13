/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    unordered_map<Node*, int> dp; 

public:
    int getMaxSum(Node* root) {
        if (root == nullptr)
            return 0;

        if (dp.find(root) != dp.end())
            return dp[root];

        int include = root->data;
        if (root->left != nullptr) {
            include += getMaxSum(root->left->left);
            include += getMaxSum(root->left->right);
        }
        if (root->right != nullptr) {
            include += getMaxSum(root->right->left);
            include += getMaxSum(root->right->right);
        }

        int exclude = getMaxSum(root->left) + getMaxSum(root->right);

        dp[root] = max(include, exclude);
        return dp[root];
    }
};