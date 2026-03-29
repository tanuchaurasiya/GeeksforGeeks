class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int tar=0;
        for(auto a:arr) tar+=a;

        vector<vector<int>> dp(n, vector<int>(tar+1,0));

        for(int i=0;i<n;i++) dp[i][0]=1;
        // cout<<tar<<endl;

        if(arr[0]<=tar) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int t=1;t<=tar;t++){
                bool nottake = dp[i-1][t];
                bool take=false;
                if(arr[i]<=t){
                    take = dp[i-1][t-arr[i]];
                }
                
                dp[i][t] = take | nottake;
            }
        }

        int res=INT_MAX;
        for(int i=0;i<tar;i++){
            if(dp[n-1][i]==false) continue;
            int sum1=i;
            int sum2=tar-sum1;
            res=min(res, abs(sum2-sum1));
        }
        return res;
    }
};
