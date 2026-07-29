class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        unordered_map<int,int> mp;
        int res=0;
        for(auto a:arr) mp[a]=1;
        
        for(auto a:arr)
        {
            if(mp[a-1]==1) continue;
            while(mp[a-1]) a--;
            res++;
        }
        return res;
        
    }
};
