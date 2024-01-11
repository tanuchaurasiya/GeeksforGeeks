//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    void findParent(Node* root, unordered_map<Node*, Node*> &mp){
        if(root==NULL) return; 
        
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        
        findParent(root->left, mp);
        findParent(root->right, mp);
    } 
    bool height(Node* root, int node, int h, int &ans){
        if(root==NULL) return false;
        
        if(root->data==node) {
            ans=h;
            return true;
        }
        
        if(height(root->left, node, h+1, ans))
             return true;   
        
        if(height(root->right, node, h+1, ans))
             return true;
        return false;
    }
     
    Node* find(Node* root, int n){
        if(root==NULL) return NULL;
        if(root->data==n) return root;
        Node* x = find(root->left,n);
        if(x) return x;
        Node* y = find(root->right,n);
        if(y) return y;
        return NULL;
        
    } 
    int LCA(Node* root, int first, int second, unordered_map<Node*, Node*> &parent) {
        int firstH, secondH;
        height(root, first, 0, firstH);
        height(root, second, 0, secondH);
        
        Node* firstN;
        Node* secondN;
        firstN = find(root, first);
        secondN = find(root, second);
        // cout<<"ans1="<<firstH<<" ans2="<<secondH<<endl;
        int c1=0;
        int c2=0;
        while(firstH>secondH){
            firstN = parent[firstN];
            firstH--;
            c1++;
        } 
        
        while(firstH<secondH){
            secondN = parent[secondN];
            // cout<<secondN->data<<endl;
            secondH--;
            c2++;
        } 
        // cout<<firstN<<" "<<secondN<<endl;
        if(firstN==secondN) return c1+c2;
        
        int c3=0;
        while(firstN!=secondN){
            c3+=2;
            firstN=parent[firstN];
            secondN = parent[secondN];
        } 
        return c1+c2+c3;
        
    }
    int findDist(Node* root, int first, int second) {
      unordered_map<Node*, Node*> parent;
      findParent(root, parent);
      return LCA(root, first, second, parent);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends