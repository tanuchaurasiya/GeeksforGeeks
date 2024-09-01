//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int n1=0;
  int n2=0;
  string s1;
  string s2;
    int help(int i, int j, vector<vector<int>> &dp){
        if(i==0){
            return j;
        }
        if(j==0) {
            return i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=help(i-1,j-1,dp);
        }
        
        else{
            dp[i][j]=1+min(help(i-1,j-1,dp), min(help(i-1,j,dp), help(i,j-1,dp)));
        }
        return dp[i][j];
    }
    int editDistance(string str1, string str2) {
        s1=str1;
        s2=str2;
        n1=s1.length();
        n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return help(n1,n2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends