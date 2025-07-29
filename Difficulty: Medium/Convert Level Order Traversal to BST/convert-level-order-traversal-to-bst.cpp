// Function to construct the BST from its given level order traversal.

Node* help(Node* root, int data){
    if(root==NULL) return new Node(data);
    
    if(root->data>data){
        root->left=help(root->left, data);
    }
    else {
        root->right=help(root->right, data);
    }
    return root;
}

Node* constructBst(int arr[], int n) {
    Node* root=new Node(arr[0]);
    for(int i=1;i<n;i++){
         auto x=help(root,arr[i]);
    }
    return root;
}