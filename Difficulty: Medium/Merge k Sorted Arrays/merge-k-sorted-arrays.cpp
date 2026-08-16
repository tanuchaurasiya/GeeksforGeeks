class Solution {
  public:
    vector<int> merge2(vector<int>& first, vector<int>& second)
    {
        int i=0;
        int j=0;
        
        int n1=first.size();
        int n2=second.size();
        
        
        vector<int> res(n1+n2);
        int k=0;
        
        while(i<n1 && j<n2)
        {
            if(first[i]<=second[j])
            {
                res[k]=first[i];
                i++;
            }
            else{
                res[k]=second[j];
                j++;
            }
            k++;
        }
        
        while(i<n1)
        {
            res[k]=first[i];
            i++;
            k++;
        }
        
        while(j<n2)
        {
            res[k]=second[j];
            j++;
            k++;
        }
        return res;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<vector<int>> matNew;
        int n=mat.size();
        while(n>1){
            for(int i=0;i<n;i+=2){
                if(i+1<n) matNew.push_back(merge2(mat[i], mat[i+1]));
                else matNew.push_back(mat[i]);
            }
            mat=matNew;
            matNew.clear();
            n=mat.size();
        }
        return mat[0];
        
    }
};