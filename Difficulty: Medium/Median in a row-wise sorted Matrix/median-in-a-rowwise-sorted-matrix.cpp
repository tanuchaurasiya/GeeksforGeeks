class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        int req=(n*m)/2;
        int low=INT_MAX;
        int high=INT_MIN;
        
        
        for(int i=0;i<n;i++) {
            low = min (low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            }
            if(cnt<=req){
                low=mid+1;
            }else
                high=mid-1;
        }
        return low;
    }
};
