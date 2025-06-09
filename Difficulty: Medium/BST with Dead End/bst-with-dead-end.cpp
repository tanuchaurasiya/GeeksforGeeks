/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool help(Node* root, int minn, int maxx)
    {
        if(root==NULL) return false;
        // cout<<"root="<<root->data<<" ";
        // if(root->left) cout<<"left="<<root->left->data<<" ";
        // if(root->right) cout<<"right="<<root->right->data<<" ";   
        // cout<<"min="<<minn<<" max="<<maxx;
        // cout<<endl;
        
        if(root->left==NULL && root->right==NULL && root->data-1==minn && root->data+1==maxx) return true;
        
        if(help(root->left, minn, root->data)) return true;
        if(help(root->right, root->data, maxx)) return true;
        return false;
    }
    bool isDeadEnd(Node *root) {
       return help(root, 0, INT_MAX);
    }
};