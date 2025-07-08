/* A binary tree node

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

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool isSameTree(Node* s, Node* t) {
        if (s ==NULL && t==NULL) return true; // Both trees are empty
        if (s==NULL || t==NULL) return false; // One tree is empty, and the other is not
        if (s->data != t->data) return false; // Values do not match
        // Recursively check left and right subtrees
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

    bool isSubTree(Node* root, Node* subRoot) {
        if (root == NULL) return false; // If root is null, subRoot cannot be a subtree
        if(isSameTree(root, subRoot)) return true; // Check if trees are identical
        // Recursively check left and right subtrees
        return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
    }
};
