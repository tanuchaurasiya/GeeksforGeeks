class Solution {
  public:
    int f(int i, int j, vector<vector<int>>& dp, vector<int>& nums){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }
        int l=f(i+1, j, dp, nums);
        if(j==-1 || nums[i]>nums[j]){
            l=max(l, nums[i]+f(i+1, i, dp, nums));
        }
        return dp[i][j+1]=l;
    }
    int maxSumIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        int r=f(0, -1, dp, nums);
        return r;
    }
};