
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void RootToLeaf(Node* root, vector<int> &v, vector<vector<int>>&res){
    v.push_back(root->data);
    if (root->left==NULL && root->right==NULL){
            res.push_back(v);
            // v.pop_back();
            return;
    } 
    else if (root->left!=NULL && root->right==NULL){
         RootToLeaf(root->left,v,res); 
         v.pop_back();
    }
    
    else if (root->left==NULL && root->right!=NULL){
         RootToLeaf(root->right,v,res); 
         v.pop_back();
    }
   
    else{
        RootToLeaf(root->left,v,res); 
        v.pop_back();
        RootToLeaf(root->right,v,res);
        v.pop_back();
    }
}

    vector<vector<int>> Paths(Node* root) {
        vector<int> v;
        vector<vector<int>> res; 
        RootToLeaf(root,v,res);
        return res;
    }
};




