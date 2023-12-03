//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int help(int r,int c,vector<vector<int>>& matrix,vector<vector<int>>& dp){
   if(dp[r][c])return dp[r][c];
   int n=matrix.size();
   int m=matrix[0].size();
   int ans=0;
   if(r+1<n && matrix[r][c]<matrix[r+1][c])ans=max(ans,help(r+1,c,matrix,dp));
   if(r-1>=0 && matrix[r][c]<matrix[r-1][c])ans=max(ans,help(r-1,c,matrix,dp));
   if(c+1<m && matrix[r][c]<matrix[r][c+1])ans=max(ans,help(r,c+1,matrix,dp));
   if(c-1>=0 && matrix[r][c]<matrix[r][c-1])ans=max(ans,help(r,c-1,matrix,dp));
   dp[r][c]=1+ans;
   return dp[r][c];
  }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!dp[i][j]){
                    help(i,j,matrix,dp);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends