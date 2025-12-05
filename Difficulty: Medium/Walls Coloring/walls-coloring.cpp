// User function Template for C++

class Solution {
  public:
    int help(int i, int prevj, vector<vector<int>> &colors, int N, vector<vector<int>>&dp)
    {
        if(i==N) return 0;
        if(dp[i][prevj+1]!=-1) return dp[i][prevj+1];
        int ans=INT_MAX;
        for(int j=0;j<3;j++)
        {
            if(j!=prevj)
            {
                ans=min(ans, colors[i][j] + help(i+1, j, colors, N, dp));
            }
        }
        return dp[i][prevj+1]=ans;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        vector<vector<int>>dp(N, vector<int>(4,-1));
       return help(0, -1, colors, N, dp);
    }
};
