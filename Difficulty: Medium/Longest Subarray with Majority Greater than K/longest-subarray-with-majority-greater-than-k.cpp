class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int N=arr.size();
        vector<int> A(N);
        for(int i=0;i<N;i++){
            if(arr[i]>k) A[i]=1;
            else A[i]=-1;
        }
        int sum=0;
        int res=0;
        
        unordered_map<int,int> prefixsum; 
        for(int i=0;i<N;i++)
            {
                sum+=A[i]; 
                if(sum>0)
                    res=max(res, i+1); 
                else if(prefixsum.find(sum-1)!=prefixsum.end())
                {
                    res=max(res, i-prefixsum[sum-1]);
                }
                
                if(prefixsum.find(sum)==prefixsum.end()) prefixsum[sum]=i;;
            }
        return res;
        
    }
};