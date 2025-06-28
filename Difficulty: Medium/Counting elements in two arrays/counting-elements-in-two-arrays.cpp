class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        int n=a.size(), m=b.size();
        vector<int>ans(n, 0);
        
        for(int i=0; i<n; i++){
            int lo=0, hi=m-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(b[mid]<=a[i]){
                    ans[i]=mid+1;
                    lo=mid+1;
                }else hi=mid-1;
            }
        }
        
        return ans;
    }
};