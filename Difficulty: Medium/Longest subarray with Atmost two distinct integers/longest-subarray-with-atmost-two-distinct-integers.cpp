class Solution {
  public:
    int totalElements(vector<int> &nums) {
        int N=nums.size();
        int i=0;
        int j=0;
        int ans=0; 
        
        int bas1=-1, bas2=-1;  
        int count1=0, count2=0;
        while(j<N){ 
            if(nums[j] == bas1) {
                count1++;
            } 
            
            else if(nums[j] == bas2) {
                count2++;
            }
            else if(bas1==-1) {
                bas1 = nums[j];  
                count1=1;
            }
            
            else if(bas2==-1) {
                bas2 = nums[j];
                count2=1;
            }
            
            else{ 
                while(count1>0 && count2>0){ 
                    if(nums[i] == bas1) count1--;
                    else if(nums[i] == bas2) count2--;
                    i++; 
                } 
                if(count1==0) {
                    count1=1;
                    bas1=nums[j];
                }
                else{
                    count2=1;
                    bas2=nums[j];
                }
            } 
            ans=max(ans, j-i+1);
            j++;
        }
        
        return ans;
        
    }
};