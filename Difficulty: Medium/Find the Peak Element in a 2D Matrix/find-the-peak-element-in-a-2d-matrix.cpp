class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool top=true,bot=true,left=true,right=true;
                if(i-1>=0&&mat[i-1][j]>mat[i][j])top=false;
                if(i+1<m&&mat[i+1][j]>mat[i][j])bot=false;
                if(j-1>=0&&mat[i][j-1]>mat[i][j])left=false;
                if(j+1<n&&mat[i][j+1]>mat[i][j])right=false;
                
                if(top&&bot&&left&&right)return {i,j};
            }
        }
        return {-1,-1};
    }
};
