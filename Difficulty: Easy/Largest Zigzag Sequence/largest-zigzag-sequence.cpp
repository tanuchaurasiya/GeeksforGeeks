class Solution {
  public:
    int dfs(vector<vector<int>>& mat, int i, int j,
            vector<vector<int>>& dp) {

        int n = mat.size();
        int m = mat[0].size();

        if(i == n - 1)
            return mat[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int best = 0;

        for(int k = 0; k < m; k++) {

            if(k != j) {
                best = max(best, dfs(mat, i + 1, k, dp));
            }

        }

        return dp[i][j] = mat[i][j] + best;
    }

    int zigzagSequence(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        // Try every possible starting element
        for(int j = 0; j < m; j++) {
            ans = max(ans, dfs(mat, 0, j, dp));
        }

        return ans;
    }
};