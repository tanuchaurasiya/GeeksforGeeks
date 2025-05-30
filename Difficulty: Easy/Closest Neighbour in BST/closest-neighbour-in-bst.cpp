/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int n) {
        int ans=-1;
        while(root)
        {
            if(root->data<=n)
            {
                ans=root->data;
                root=root->right;
            }
            else if(root->data>n)
                root=root->left;
        }
        return ans;
        
    }
};