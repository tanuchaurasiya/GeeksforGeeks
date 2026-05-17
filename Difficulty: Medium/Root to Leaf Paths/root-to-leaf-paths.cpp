/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void help(Node* root, vector<int>temp, vector<vector<int>> &res)
    {
        if(root->left==NULL && root->right==NULL) {
            temp.push_back(root->data);
            res.push_back(temp);
            return;
        }
        temp.push_back(root->data);
        if(root->left) help(root->left, temp, res);
        if(root->right) help(root->right, temp, res);
    }
        
    vector<vector<int>> Paths(Node* root) {
        if(root==NULL) return {{}};
        vector<vector<int>> res;
        vector<int>temp;
        help(root, temp,res);
        return res;
        
    }
};