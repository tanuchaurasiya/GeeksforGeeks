// User function Template for C++

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> moves{{-1,0}, {1, 0}, {0,-1}, {0,1}};
    
    bool isvalid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    
    int help(int i, int j, int m ,int n,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(auto adj:moves){
            if(isvalid(i+adj[0], j+adj[1], m, n) && matrix[i][j]<matrix[i+adj[0]][j+adj[1]]){
                ans=max(ans, 1+help(i+adj[0], j+adj[1], m, n, matrix));
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        dp.resize(n, vector<int>(m,-1));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                res=max(res, help(i, j, n, m, matrix));
            }
        }
        return res;
    }
};

