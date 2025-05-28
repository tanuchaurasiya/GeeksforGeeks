class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==1)
                {
                    for(int k=j+1;k<c;k++)
                    {
                        if(mat[i][k]==1)
                        {
                            for(int l=i+1;l<r;l++)
                            {
                                if(mat[l][k]==1)
                                {
                                    if(mat[l][j]==1)
                                    {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};