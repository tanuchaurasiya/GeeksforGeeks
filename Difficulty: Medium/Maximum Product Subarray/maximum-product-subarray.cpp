class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // code here
        int n = nums.size();
        int res=-1e9;
	    int prefix=1;
        int suffix=1;
        for(int i=0;i<n;i++){
            if (prefix==0)
                prefix=1;
            if (suffix==0)
                suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            res=max(res,max(prefix,suffix));
        }
        return res;
    }
};