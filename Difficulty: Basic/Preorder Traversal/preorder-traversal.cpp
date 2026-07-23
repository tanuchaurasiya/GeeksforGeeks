/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        stack<Node*> st;
        vector<int> res;
        
        while(!st.empty() || root!=NULL){
            while(root){
                st.push(root);
                res.push_back(root->data);
                root=root->left;
            }
            root=st.top()->right;
            st.pop();
        }
        return res;
    }
};