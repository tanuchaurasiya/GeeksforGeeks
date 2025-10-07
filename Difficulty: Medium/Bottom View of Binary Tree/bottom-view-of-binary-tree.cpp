//Function to return a list containing the bottom view of the given tree.
// #include<bits/stdc++.h>

class Solution {
  public:
    // static bool comparator(pair<int,int> p1, pair<int,int> p2){
    //   // custom definition code 
    //     if(p1.first>=p2.first) 
    //       return true;
    //     return false;
    // }
    
    void help(Node *root, int row, int col, unordered_map<int, pair<int,int>> &mp){  
        if (root==NULL) 
            return ;
        
    
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
        
        unordered_map<int, pair<int,int>> mp;
        help(root, 0, 0, mp); 
        
        vector<int> keys; 
        
        for(auto i:mp){
            keys.push_back(i.first); 
            // cout<<i.first<<endl;
        } 
        sort(keys.begin(), keys.end()); 
        vector<int> res; 
        
        
        for(auto key:keys){
            res.push_back(mp[key].second);
        } 
        
        return res;
        
    }
};


