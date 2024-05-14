//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 + 7;
	int solve(int *arr, int n, int sum, vector<vector<int>>&dp){
    if(n==0){
        return (arr[0]==sum) + (sum==0);
    }
    if(dp[n][sum]!=-1)return dp[n][sum];
    int notpick = solve(arr, n-1, sum,dp);
    int pick=0;
    if(arr[n]<=sum ) pick = solve(arr, n-1, sum-arr[n], dp);
    return dp[n][sum]=(pick+notpick)%mod;
}
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>>dp(n+1, vector<int>(sum+1, -1)); 
      return solve(arr, n-1, sum, dp);
}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends