class Solution {
  public:
    int hIndex(vector<int>& c) {
        // code here
        int n=c.size();
        sort(c.begin(), c.end());
        int maxh=0;
        for(int i=0;i<n;i++){
            int h=c[i];
            int times=n-i;
            maxh=max(maxh,min(h, times));
        }
        return maxh;
        
    }
};