class Solution {
  public:
    int n;
    vector<vector<int>> dp;
    int help(int prev,int curr, vector<int>& arr)
    {
        if(curr==n) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int take=0;
        int nottake=0;
        
        if(prev==-1 || arr[curr]>arr[prev]) take=arr[curr]+help(curr, curr+1, arr);
        nottake= help(prev, curr+1, arr);
        return dp[prev+1][curr]=max(take, nottake);
    }
    int maxSumIS(vector<int>& arr) {
        n=arr.size();
        dp.resize(n, vector<int>(n,-1));
        return help(-1, 0, arr);
    }
};