//Function to return a list containing the bottom view of the given tree.
// #include<bits/stdc++.h>

class Solution {
  public:
   int min_key=INT_MAX;
   int max_key=INT_MIN;
    void help(Node *root, int row, int col, unordered_map<int, pair<int,int>> &mp){  
        if (root==NULL) 
            return ;
        
        min_key=min(min_key, col);
        max_key=max(max_key, col);
    
        if(mp.find(col)==mp.end()) {
            mp[col]={row,root->data};
        }
        else {
            if((*mp.find(col)).second.first<=row) {
                mp[col]={row,root->data};
            }
        }
        
        help(root->left, row+1, col-1, mp); 
        help(root->right, row+1, col+1, mp); 
    }
    

    vector <int> bottomView(Node *root){ 
        if(root==NULL) return {};
        unordered_map<int, pair<int,int>> mp;
        help(root, 0, 0, mp); 
        vector<int> res; 
        
        
        for(int key=min_key; key<=max_key; key++){
            res.push_back(mp[key].second);
        } 
        
        return res;
        
    }
};


