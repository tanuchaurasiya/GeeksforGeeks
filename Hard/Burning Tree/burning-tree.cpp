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
  void storeParent(Node* root, unordered_map<Node*,Node*> &parent){
        if(root==NULL) return;
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right] = root;
        storeParent(root->left, parent);
        storeParent(root->right, parent);
    }
    Node* findStart(int start, Node* root){ 
        if(root==NULL) return NULL;
        
        if(root->data==start) return root;
        
        Node* l = findStart(start, root->left);
        if(l) return l;
        
        Node* r = findStart(start, root->right);
        if(r) return r;
        return NULL;
        
    }
    int minTime(Node* root, int start)  {
        unordered_map<Node*, Node*> parent;
        storeParent(root, parent);
        queue<pair<Node*, int>> q;
        Node* x = findStart(start, root);
        q.push({x, 0});
        
        unordered_map<int,int> visited;
        visited[start]=1;
        int res=0;
        while(!q.empty()){
            Node* node = q.front().first;
            int time = q.front().second;
            q.pop();
            if(time > res)
                res=time;
            Node* par = parent[node];
            Node* chi1 = node->left;
            Node* chi2 = node->right;
            if(par && visited[par->data]==0) {
                visited[par->data] = 1;
                q.push({par,time+1});
            }
            
            if(chi1 && visited[chi1->data]==0) {
                visited[chi1->data] = 1;
                q.push({chi1, time+1});
            }
            
            if(chi2 && visited[chi2->data]==0) {
                visited[chi2->data] = 1;
                q.push({chi2, time+1});
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