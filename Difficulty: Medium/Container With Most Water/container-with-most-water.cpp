class Solution {
  public:
    int maxWater(vector<int> &height) {
        int n=height.size();
        int l=0;
        int r=n-1;
    
        int res=0;
    
        while(l<r){
            res=max(res, (r-l)*min(height[l], height[r]));
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return res;
        
    }
};