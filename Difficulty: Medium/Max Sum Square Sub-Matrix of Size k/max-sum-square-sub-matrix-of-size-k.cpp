class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int ans = INT_MIN;
        int n=mat.size();
        for(int i = 0 ;i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                
                int x = 0;
                int y = 0;
                int z=0;
                
                if(i-1>=0) x=mat[i-1][j];
                if(j-1>=0) y=mat[i][j-1];
                if(i-1>=0 && j-1>=0) z=mat[i-1][j-1];
                
                mat[i][j]=x+y+mat[i][j]-z;
    
                if(i+1>=k && j+1>=k) {
                    x = 0;
                    y = 0;
                    z = 0;
                    
                    if(i-k>=0) x=mat[i-k][j];
                    if(j-k>=0) y=mat[i][j-k];
                    
                    if(i-k>=0 && j-k>=0) z=mat[i-k][j-k];
                    ans = max(ans  , mat[i][j]-x-y+z);
                }
            }
        }
        return ans;
    }
};