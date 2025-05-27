
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
  public:
  TreeNode* help(vector<int>& preorder, int &i, int upper, vector<int> &res){
        if(i>=preorder.size() || preorder[i]> upper) return NULL;
        TreeNode* root=  new TreeNode(preorder[i++]); 
        root->left = help(preorder, i, root->val, res);
        root->right = help(preorder, i, upper, res);
        if(root->left==NULL && root->right==NULL) res.push_back(root->val);
        return root;
    }

    vector<int> leafNodes(vector<int>& preorder) {
        int upper = INT_MAX;
        int i=0;
        vector<int> res;
        auto r = help(preorder, i, upper, res);
        return res;
    }
};