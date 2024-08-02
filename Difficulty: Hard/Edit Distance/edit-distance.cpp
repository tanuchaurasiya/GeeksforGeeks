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
        if(i==n1 && j==n2) return 0;
        if(i==n1){
            return (n2-j);
        }
        if(j==n2) {
            return (n1-i);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int x=INT_MAX;
        int y=INT_MAX;
        if(s1[i]==s2[j]){
            x=help(i+1,j+1,dp);
        }
        
        else{
            y=1+min(help(i+1,j+1,dp), min(help(i+1,j,dp), help(i,j+1,dp)));
            
        }
        dp[i][j] = min(x, y);
        return dp[i][j];
    }
    int editDistance(string str1, string str2) {
        s1=str1;
        s2=str2;
        n1=s1.length();
        n2=s2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return help(0,0,dp);
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