/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int res=-1;
    void help(Node *root, int& K){
        if(root==NULL) return;
        help(root->left, K);
        K--;
        if(K==0){
            res=root->data;
            return;
        }
        help(root->right,K);
    }
    int kthSmallest(Node *root, int K) {
        help(root,K);
        return res;
    }
};
