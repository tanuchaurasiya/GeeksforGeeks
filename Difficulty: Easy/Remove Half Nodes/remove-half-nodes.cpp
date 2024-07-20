//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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

// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node* res=NULL;
    void help(Node* root, Node* parent, int isLeft){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        // cout<<root->data<<endl;
        if(root->left!=NULL && root->right!=NULL){
            help(root->left, root, 1);
            help(root->right, root, 2);
        }
        
        else if(root->left!=NULL){
            if(isLeft==0){
                // cout<<"117\n";
                res=root->left;
                help(root->left, root->left, 0);
            }
            else if(isLeft==1) {
                // cout<<"122\n";
                parent->left = root->left;
                help(root->left, parent, 1);
            }
            else {
                // cout<<"127\n";
                parent->right = root->left;
                help(root->left, parent, 2);
            }
            
            
        }
        else{
            if(isLeft==0){
                // cout<<"136\n";
                res=root->right;
                help(root->right, root->right, 0);
            }
            else if(isLeft==1){
                // cout<<"141\n";
                parent->left = root->right;
                help(root->right, parent, 1);
            } 
            else {
                // cout<<"146\n";
                parent->right = root->right;
                help(root->right, parent, 2);
            }
            
        }
        return;
    }
    
    Node *RemoveHalfNodes(Node *root) {
        res=root;
        help(root, root,0);
        return res;
    }
};















//{ Driver Code Starts.
int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node* fresh = obj.RemoveHalfNodes(root);
        inorder(fresh);
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends