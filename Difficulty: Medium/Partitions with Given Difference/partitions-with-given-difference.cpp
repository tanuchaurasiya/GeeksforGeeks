class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int totalSum=0;
        int mod=1e9+7;
        int n=arr.size();
        for(int i=0;i<n;i++) totalSum+=arr[i];
        vector<vector<int>> dp;
    
        if((totalSum-d<0) || ((totalSum-d)%2)) return 0;
        
        int target = (totalSum-d)/2;
        dp.resize(n, vector<int>(target+1,0));
        
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        
        
        if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                int nottake = dp[i-1][t];
                int take=0;
                if(arr[i]<=t){
                    take = dp[i-1][t-arr[i]];
                }
                
                dp[i][t] = (take + nottake)%mod;
            }
        }
        
        
        return dp[n-1][target];
        
    }
};