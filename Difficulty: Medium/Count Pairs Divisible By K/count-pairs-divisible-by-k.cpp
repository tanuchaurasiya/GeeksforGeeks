class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<long long,long long> mp; 
        long long count=0;
        for(int i=0;i<n;i++){
            int rem = arr[i]%k; 
            // cout<<rem<<" "<<(k-rem)%k<<" "<<mp[(k-rem)%k]<<endl;
            if(mp[(k-rem)%k]!=0) count+=mp[(k-rem)%k];
            mp[rem]++;
        }
        return count;
        
    }
};