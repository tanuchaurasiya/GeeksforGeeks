//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int solve(Node* root,int &moves){
       
       if(root== NULL)return 0;
       
       int lf=solve(root->left,moves);
       int rf=solve(root->right,moves);
       
       moves+=abs(lf)+abs(rf);
       return root->data-1+lf+rf;
   }
   
   int distCandy(Node* root)
   {
       int moves=0;
       solve(root,moves);
       return moves;
   }
};
