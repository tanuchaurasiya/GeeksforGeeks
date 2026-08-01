class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        vector<int> res(n);
        
        for(int i=0;i<a.size();i++){
            int l=a[i];
            int r=b[i];
            int v=k[i];
            
            res[l]+=v;
            if(r+1<n) res[r+1]-=v;
        }
        
        int ans=res[0];
        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
            ans=max(ans, res[i]);
        }
        return ans;
    }
};