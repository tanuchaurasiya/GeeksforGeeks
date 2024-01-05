//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	int help(int i, int prev, vector<vector<int>> &dp){
	    if(i==-1) return 1;
	   
	   if(dp[i][prev]!=-1) return dp[i][prev];
	    int a=0;
	    int b=0;
	    
	    if(prev==0 || prev==1){
	        a = help(i-1, 1, dp) % mod;
	        b = help(i-1, 2, dp) % mod;
	    } 
	    else
	        a =  help(i-1, 1, dp) % mod;
	       
	    dp[i][prev] = (a+b)%mod;
	    return dp[i][prev];
	    
	}
	int TotalWays(int N)
	{ 
	   // 0 for start, 1 for empty space, 2 for building
	   
	    vector<vector<int>> dp(N, vector<int>(3,-1));
	    long long int res = help(N-1, 0, dp) % mod; 
	    return (res*res)%mod;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends