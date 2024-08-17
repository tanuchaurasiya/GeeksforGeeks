//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution{
    unordered_map<int, unordered_map<int, int>> dp;
	public:
	int solve(int m, int n)
	{
	    if(m == n)
	    {
	        return 1;
	    }
	    if(m == 1)
	    {
	        return n;
	    }
	    if(n == 1)
	    {
	        return m;
	    }
	    if(m == 0 || n == 0) return 0;
	    if(dp[m].find(n) != dp[m].end())
	        return dp[m][n];
	   // if(dp[n].find(m) != dp[n].end())
	   //     return dp[n][m];
	        
	    int m1 = min(m, n);
	    int ans = INT_MAX;
	    for(int i=1; i<=m1; i++)
	    {
	        ans = min(ans, 1+min((solve(m-i, n)+solve(i, n-i)),(solve(m, n-i)+solve(m-i, i))));
	    }
	    return dp[m][n]  = ans;
	}
	int minCut(int M, int N)
	{
	   
	   return solve(M, N);
        // Your code goes here
	}
};





//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

	    

	    Solution ob;
	    cout << ob.minCut(m, n) << "\n";

	     
    }
    return 0;
}

// } Driver Code Ends