/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            Node* node = q.front().first;
            int c = q.front().second;
            q.pop();
            
            m[c].push_back(node->data);
            if(node->left) q.push({node->left, c-1});
            if(node->right) q.push({node->right, c+1});
        }
        for(auto it: m) ans.push_back(it.second);
        return ans;
        
    }
};