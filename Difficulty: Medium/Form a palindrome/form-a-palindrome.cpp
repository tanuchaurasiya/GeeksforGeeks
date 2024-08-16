//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(string &s, int &n, int i, int j, vector<vector<int>>&dp){
        if(i == j || i>j)
            return 0;
        
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            dp[i][j] =  solve(s,n,i+1,j-1, dp);
        }else{
            dp[i][j] =  1 + min(solve(s,n,i,j-1, dp), solve(s,n,i+1,j, dp));
        }
        
        return dp[i][j];
    }
    int findMinInsertions(string s){
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // code here 
         return solve(s, n, 0, s.length()-1, dp);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends