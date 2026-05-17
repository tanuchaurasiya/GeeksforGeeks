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
    void leftTraversal(Node* root, vector<int>& left)
    {
        while(root)
        {
            if(root->left!=NULL || root->right!=NULL) left.push_back(root->data);
            if(root->left) root=root->left;
            else root=root->right;
        }
    }
    
    void rightTraversal(Node* root, vector<int>& right)
    {
        while(root)
        {
            if(root->left!=NULL || root->right!=NULL) right.push_back(root->data);
            if(root->right) root=root->right;
            else root=root->left;
        }
    }
    
    void leafNodes(Node* root, vector<int>& leaves)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            leaves.push_back(root->data); 
            return;
        }
        leafNodes(root->left, leaves);
        leafNodes(root->right, leaves);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {root->data};
        
        vector<int>left;
        vector<int>right;
        vector<int>leaves;
        
        vector<int> res{root->data};
        leftTraversal(root->left, left);
        rightTraversal(root->right, right);
        leafNodes(root, leaves);
        
        for(auto i:left) {res.push_back(i);}
        for(auto i: leaves) {res.push_back(i);}
        for(int i=right.size()-1; i>=0; i--) {res.push_back(right[i]);}
        return res;

        
    }
};