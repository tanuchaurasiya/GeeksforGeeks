class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int rsum=0;
        int csum=0;
        int r=mat.size();
        int c=mat[0].size();
        
        int maxSum=INT_MIN;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                rsum+=mat[i][j];
            }
            maxSum=max(maxSum,rsum);
            rsum=0;
        }
        
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++){
                csum+=mat[j][i];
            }
            maxSum=max(maxSum,csum);
            csum=0;
        }
        
        // cout<<"maxSum="<<maxSum<<endl;
        int res=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                rsum+=mat[i][j];
            }
            res+=maxSum-rsum;
            rsum=0;
        }
        return res;
        
    }
};