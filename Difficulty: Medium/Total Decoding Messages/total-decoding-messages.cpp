class Solution {
  public:
    unordered_map<string, int> mp;
    vector<int> dp;
    long long int help(long long int i, string &s, long long int& n)
    {
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        long long int ans=0;
        
        for(long long int idx=i;idx<n;idx++)
        {
            if(idx+1<n && s[idx+1]=='0') continue;
            if(idx-i+1>2 || mp[s.substr(i, idx-i+1)]==0) continue;
            ans+=help(idx+1, s, n);
        }
        return dp[i]=ans;
    }
    int countWays(string &s) {
        for(int i = 1; i <= 26; i++)
        {
            mp[to_string(i)] = i;
        }
        long long int n=s.size();
        dp.resize(n,-1);
        return help(0, s,n);
        
    }
};