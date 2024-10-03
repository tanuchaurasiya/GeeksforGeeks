//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
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

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends