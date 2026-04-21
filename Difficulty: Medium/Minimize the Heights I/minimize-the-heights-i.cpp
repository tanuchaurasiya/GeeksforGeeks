// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=arr[n-1]-arr[0];
        
        int small=arr[0]+k;
        int large=arr[n-1]-k;
        
        int mi,ma;
        for(int i=0;i<n-1;i++){
            mi=min(small,arr[i+1]-k);
            ma=max(large,arr[i]+k);
            ans=min(ans,ma-mi);
        }
        return ans;
        
    }
};