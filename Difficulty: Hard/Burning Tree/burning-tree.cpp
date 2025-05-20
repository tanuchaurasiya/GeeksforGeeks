//User function Template for C++

/*
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
    unordered_map<Node*,Node*> parent;
    
    void feedParent(Node* root){
        if(root==NULL) return;
        
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        feedParent(root->left);
        feedParent(root->right);
    }
    Node* findTar(Node* root, int target)
    {
        if(root==NULL) return root;
        
        if(root->data==target) return root;
        
        auto left = findTar(root->left, target);
        if(left) return left;
        
        auto right = findTar(root->right, target);
        if(right) return right;
        
        return NULL;
    }
    int minTime(Node* root, int target) 
    {
        feedParent(root);
        
        queue<pair<Node*, int>> q;
        auto tar = findTar(root, target);
        q.push({tar,0});
        int res=0;
        unordered_map<Node*,int> vis;
        vis[tar]=1;
        while(!q.empty()){
            auto n = q.front().first;
            auto d = q.front().second;
            q.pop();
            res=max(res, d);
            // cout<<n->data<<" "<<d<<endl;
            if(parent[n] && vis[parent[n]]==0){
                q.push({parent[n], d+1});
                vis[parent[n]]=1;
            }
            
            if(n->left && vis[n->left]==0){
                q.push({n->left, d+1});
                vis[n->left]=1;
            }
            
            if(n->right && vis[n->right]==0){
                q.push({n->right, d+1});
                vis[n->right]=1;
            }
            
        }
        
        return res;
        
    }
};
