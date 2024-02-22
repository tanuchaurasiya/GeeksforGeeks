//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    private:
    int mod = 1e9+7;
    public: 
    int help(int i, int j, string s, string t, int n1, int n2, vector<vector<int>> &dp){
        if(j==n2) {
            return 1;
        }
        if(i>=n1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int x =0;
        int y =0;
        if(s[i]==t[j]) 
            x = help(i+1, j+1, s, t, n1, n2, dp); 
        y =  help(i+1, j, s, t, n1, n2,dp);
        dp[i][j] = (x+y)%mod;
        return dp[i][j];
    }
    int subsequenceCount(string s, string t) { 
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>>dp(n1, vector<int>(n2,-1)); 
        int r = help(0,0,s,t, n1, n2, dp) % mod;
        return r;
    }

};
 



//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends