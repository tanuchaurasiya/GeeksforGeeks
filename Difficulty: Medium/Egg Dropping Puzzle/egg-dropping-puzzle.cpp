//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int help(int n, int k, vector<vector<int>> &dp)
    {
        // If there are no floors,
        // then no trials needed.
        // OR if there is one floor,
        // one trial needed.
        if (k == 1 || k == 0)
            return k;
    
        // We need k trials for one
        // egg and k floors
        if (n == 1)
            return k;
            
        if(dp[n][k]!=-1) return dp[n][k];
    
        int min = INT_MAX, x, res;
    
        // Consider all droppings from
        // 1st floor to kth floor and
        // return the minimum of these
        // values plus 1.
        for (x = 1; x <= k; x++) {
            res = max(help(n - 1, x - 1,dp), help(n, k - x,dp));
            if (res < min)
                min = res;
        }
    
        dp[n][k] = min + 1;
        return dp[n][k];
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1, -1));
        return help(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends