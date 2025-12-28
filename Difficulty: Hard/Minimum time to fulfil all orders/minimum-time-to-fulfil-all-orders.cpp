class Solution {
  public:
    int help(int time, vector<int>& ranks, int n)
    {
        long long donuts = 0;
        for(int i=0;i<n;i++){
            //sum of r+2r+3r+.... = time 
            // r*n(n+1)/2=time, so n value will be as given below
          donuts += (-1+ sqrt(1 + 8.0 * time / ranks[i])) / 2;
        }
        return donuts;
    }
    int minTime(vector<int>& ranks, int n) {
        long long low = 0;
        long long high = 1LL * n * (n + 1) / 2 * (*min_element(ranks.begin(), ranks.end()));
        long long ans = high;
        long long size=ranks.size();
        while(low<=high){
            long long mid = (high+low)/2;
            if(help(mid, ranks, size)>=n){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};