/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  unordered_map<int,int> f(Node* root)
  {
        unordered_map<int,int>mpp; //{node-->index}
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* node=q.front().first;
            int k=q.front().second;
            mpp[node->data]=k;
            q.pop();
            if(node->left)
            {
                q.push({node->left,2*k+1});
            }
            if(node->right)
            {
                q.push({node->right,2*k+2});
            }
        }
        return mpp;
  }
    bool isSubTree(Node *root1, Node *root2) {
        unordered_map<int,int>r2=f(root2);
        queue<Node*>q;
        q.push(root1);
        while(!q.empty())
        {
            Node* node=q.front();
            unordered_map<int,int>r1=f(node);
            q.pop();
            if(r1==r2)
            {
                return true;
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return false;
    }
};