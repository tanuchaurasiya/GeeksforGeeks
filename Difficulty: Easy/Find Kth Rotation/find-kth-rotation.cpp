class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int l=0;
        int r=nums.size()-1;
        int ans=nums[0];
        int ansIdx=0;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(nums[l]<=nums[mid]){
                if(ans>nums[l])
                {
                    ans=nums[l];
                    ansIdx=l;
                }
                l=mid+1;
            }
            else{
                if(ans>nums[mid])
                {
                    ans=nums[mid];
                    ansIdx=mid;
                }
                r=mid-1;
            }
        }

        return ansIdx;
    }
};
