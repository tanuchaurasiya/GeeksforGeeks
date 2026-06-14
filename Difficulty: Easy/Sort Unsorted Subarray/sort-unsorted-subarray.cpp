class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return {0,0};
        int low=-1;
        int high=-1;
        
        
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1] && (low==-1 || arr[low]>arr[i])){
                low=i;
            }
            
            if(arr[n-i-1]>arr[n-i] &&(high==-1 || arr[high]<arr[n-i-1])){
                high=n-i-1;
            }
        }
        // cout<<low<<" "<<high<<endl;
        if(low==-1 || high==-1) return {0,0};
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>arr[low]) {
                low=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<arr[high]) {
                high=i;
                break;
            }
        }
        return {low,high};

        
    }
};