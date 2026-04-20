class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       int res=0;
       int xorr=0;
       unordered_map<int,int> mp;
      
       
       for(int i=0;i<arr.size();i++)
       {
           xorr^=arr[i];
           auto check=k^xorr;
           if(xorr==k) res++;
           res+=mp[check];
           mp[xorr]++;
       }
       return res;
        
    }
};