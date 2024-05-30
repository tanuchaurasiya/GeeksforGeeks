//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int mod = 1e9+7;
   int help(int i, int j, int m, int n, string s1, string s2, vector<vector<int>> &dp){
    //   cout<<i<<" "<<j<<endl;
       if(j==n) return 1;
       if(i==m) return 0;
       if(dp[i][j] !=-1 ) return dp[i][j];
       int take=0;
       int nottake=0;
       
       if(s1[i]==s2[j]){
           take = help(i+1, j+1, m, n, s1, s2,dp);
       }
       
       nottake = help(i+1, j, m, n ,s1, s2,dp);
       return dp[i][j] =  (take+nottake)%mod;
   }
    int countWays(string s1, string s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return help(0, 0, m, n, s1,s2, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends