//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int help(int i, int n, int W, int val[], int wt[], vector<unordered_map<int, int>> &dp){
        if(i>=n || W==0) return 0;
        int take=0;
        int nottake=0;
        if(dp[i][W]!=0) return dp[i][W];
        if(W>=wt[i]){
            take = val[i]+help(i, n, W-wt[i], val, wt, dp);
        }
        nottake = help(i+1, n, W, val, wt, dp);
        
        dp[i][W] = max(take, nottake);
        return dp[i][W];
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<unordered_map<int, int>> dp(n);
        return help(0, n ,W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends