class Solution {
  public:
    int help(int dis, vector<int> &stalls, int n){
        int i=0;
        int pos=stalls[i];
        int cows=1;
        i++;
        while(i<n){
            if(stalls[i]-pos>=dis){
                cows++;
                pos=stalls[i];
            }
            i++;
        }
        return cows;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        sort(stalls.begin(), stalls.end());
        int l=0;
        int r=stalls[n-1]-stalls[0];
        int mid;
        int ans=INT_MIN;
        while(l<=r){
            mid=(l+r)/2;
            
            int x=help(mid, stalls, n);
            if(x<k){
                r=mid-1;
            }
            else{
                ans=max(ans, mid);
                l=mid+1;
            }
            // cout<<mid<<" "<<x<<endl;
        }
        return ans;
    }
};