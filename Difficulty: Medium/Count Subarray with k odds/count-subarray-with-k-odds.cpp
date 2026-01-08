class Solution {
  public:
   int help(int k, vector<int>& nums, int n){
        if(k<0) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r<n){
            sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int countSubarrays(vector<int>& nums, int k) {
        return help(k, nums, nums.size()) - help(k-1, nums, nums.size());
    }
};