class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        int currXor=arr[0];
        for(int i=1;i<k;i++) currXor^=arr[i];
        int maxXor=currXor;
        // cout<<"maxXor="<<maxXor<<endl;
        
        for(int i=k;i<n;i++)
        {
            currXor^=arr[i-k];
            currXor^=arr[i];
            
            // cout<<"curXor="<<currXor<<endl;
            
            if(currXor>maxXor) maxXor=currXor;
        }
        return maxXor;
        
    }
};