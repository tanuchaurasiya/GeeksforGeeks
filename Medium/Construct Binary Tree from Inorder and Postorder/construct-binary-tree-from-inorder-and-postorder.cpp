//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    Node* help(int postorder[], int inorder[], int &postIdx, int inorStart, int inorEnd, unordered_map<int,int> &mp, int n){
        if((postIdx< 0)  || (inorStart>inorEnd))  
            return NULL; 
        
        int ele=postorder[postIdx--];
        Node* root=new Node(ele);
        int idx=mp[ele];
        
        root->right = help(postorder,inorder, postIdx,idx+1, inorEnd,mp, n);
        root->left = help(postorder, inorder, postIdx, inorStart, idx-1, mp, n); 
          
        return root;
    }
    Node *buildTree(int inorder[], int postorder[], int n) { 
        unordered_map<int,int> mp; 
    
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int postIdx=n-1;
        return help(postorder, inorder, postIdx, 0, n-1, mp, n);
    }
     
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends