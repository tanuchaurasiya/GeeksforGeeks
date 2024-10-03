//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution
{   public:
    int mod=1000000007;
    long long int solver(int m,int n, vector<vector<long long>>&dp){
        if (m == 1 || n == 1) {
            return 1;
        }

        if (dp[m][n] != -1)
            return dp[m][n];

        return dp[m][n]=(solver(m, n - 1, dp)%mod+solver(m-1, n , dp)%mod)%mod;
    }

    long long int numberOfPaths(int m, int n){
        vector<vector<long long>>dp(m+1, vector<long long>(n+1, -1));
        return solver(m, n, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends