class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        int l=0;
        int r=0;
        int n=arr.size();
        int res=0;
        while(r<n)
        {
            mp[arr[r]]++;
            if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0) mp.erase(arr[l]);
                    l++;
                }
            }
            res+=(r-l)+1;
            r++;
        }
        return res;
        
    }
};