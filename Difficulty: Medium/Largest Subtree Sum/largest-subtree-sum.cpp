/* structure of binary tree node
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
  public:
    int res=INT_MIN;
    int help(Node* root){
        if(!root) return 0;
        int left=help(root->left);
        int right=help(root->right);
        
        res=max(res, left+right+root->data);
        return left+right+root->data;
    }
    int maxSubtreeSum(Node* root) {
        help(root);
        return res;
        
    }
};
