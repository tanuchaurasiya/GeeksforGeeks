//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

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
    Node* LCA(Node* root, int first, int second, unordered_map<Node*, Node*> &parent) {
        int firstH, secondH;
        height(root, first, 0, firstH);
        height(root, second, 0, secondH);
        
        Node* firstN;
        Node* secondN;
        firstN = find(root, first);
        secondN = find(root, second);
       
        int c1=0;
        int c2=0;
        while(firstH>secondH){
            firstN = parent[firstN];
            firstH--;
            c1++;
        } 
        
        while(firstH<secondH){
            secondN = parent[secondN];
            secondH--;
            c2++;
        } 
        
        while(firstN!=secondN){
            firstN=parent[firstN];
            secondN = parent[secondN];
        } 
        return firstN;
        
    }
    int turns(Node *root, int a,int b,bool flag)
   {
       if(root)
       {
           if(root->data==a || root->data==b)return 0;
           
           if(flag==false)
           {
               return min(turns(root->left,a,b,false),1+turns(root->right,a,b,true)) ;
           }
           else
           {
                return min(1+turns(root->left,a,b,false),turns(root->right,a,b,true)) ;
           }
       }
       
       return 1e3 ;
   }
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      unordered_map<Node*, Node*> parent;
      findParent(root, parent);
       Node *lca = LCA(root,first,second, parent);
        if(lca->data!=first && lca->data!=second) 
        {
            int a=turns(lca->left,first,second,false);
            int b=turns(lca->right,first,second,true);
            return a+b+1;
        }
        else 
        {
               
           int a=turns(lca->left,first,second,false);
           int b=turns(lca->right,first,second,true);
           
           if(a==1000 && b==1000) return -1 ;
           int c=a+b-1000;
           if(c==0) return -1 ;
           
           return c ;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends