/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* help(vector<int>& preorder, vector<int>& preMirror, int &preIdx, int preStart, int preEnd, unordered_map<int,int> &mp, int n){
        if((preIdx>= n)  || (preStart>preEnd))  
            return NULL; 
        
        Node* root=new Node(preorder[preIdx++]);
        
        if (preStart == preEnd || preIdx == n) return root;
        
        int idx=mp[preorder[preIdx]];
        
        root->left = help(preorder, preMirror, preIdx, idx, preEnd, mp, n); 
        root->right = help(preorder, preMirror, preIdx, preStart+1, idx-1, mp, n);  
        return root;
    }

    Node *constructBinaryTree(vector<int> &preorder, vector<int> &preMirror) {
        unordered_map<int,int> mp; 
        
        int n=preMirror.size(); 
        for(int i=0;i<n;i++)
        {
            mp[preMirror[i]]=i;
        }
        int preIdx=0;
        return help(preorder, preMirror, preIdx, 0, n-1, mp, n);
        
    }
};