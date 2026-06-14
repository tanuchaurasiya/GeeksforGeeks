/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    Node* head = NULL;
    Node* prev = NULL;
    Node* bToDLL(Node* root) {
        if (root == NULL) return NULL;
        bToDLL(root->left);
        if (prev == NULL) head = root; 
        else { root->left = prev; prev->right = root; }
        prev = root;
        bToDLL(root->right);
        return head;
    }
};