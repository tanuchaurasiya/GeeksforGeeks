/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> help(Node* root, int lower, int upper)
    {
        if(root==NULL) return {0, INT_MIN, INT_MAX};
        auto left=help(root->left, lower, root->data);
        auto right=help(root->right, root->data, upper);
        
        if(root->data>left[1] && root->data<right[2]) 
            return {1+left[0]+right[0], max(root->data, right[1]), min(root->data,left[2])};
        return {max(left[0],right[0]), INT_MAX, INT_MIN};
    }
    int largestBst(Node *root) {
        auto res=help(root, INT_MIN, INT_MAX);
        return res[0];
    }
};