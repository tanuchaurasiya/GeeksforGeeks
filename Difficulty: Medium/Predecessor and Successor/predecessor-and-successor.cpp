
/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void check_pre(Node* root , int x , Node* &pre)
    {
        if(root == NULL)
            return ;
        if(root->data < x)
        {
            pre = root;
            check_pre(root->right, x , pre);    
        }
        else
        {
            check_pre(root->left, x ,pre);    
        }
        
    } 
    
    void check_suc(Node* root , int x , Node* &suc)
    {
        if(root == NULL)
            return ;
        if(root->data > x)
        {
            suc = root;
            check_suc(root->left, x , suc);    
        }
        else
        {
            check_suc(root->right, x ,suc);    
        }
        
    }
    vector<Node*> findPreSuc(Node* root, int key) 
    {
        Node* suc=NULL;
        Node* pre=NULL;
        check_pre(root,key,pre);
        check_suc(root, key, suc);
        return {pre,suc};
    }
};

