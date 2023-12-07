//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
        
    }
    void help(int idx, string s, int n, vector<vector<string>> &res, vector<string> &path){
        if(idx==n) {
            res.push_back(path);
            return;
        } 
        
        for(int i=idx;i<n;i++){
            if(isPalindrome(s, idx, i)){
                // cout<<"s="<<s.substr(idx,i-idx+1)<<" idx="<<idx<<" i="<<i<<endl;
                path.push_back(s.substr(idx,i-idx+1)); 
                help(i+1, s, n, res, path);
                path.pop_back();
                
            } 
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;
        help(0, s, n, res, path); 
        return res;
    }
     
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends