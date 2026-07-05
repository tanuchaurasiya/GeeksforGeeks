class Solution {
  public:
    int maxCharGap(string &s) {
        int n=s.length();
        vector<int> first(26,-1);
        vector<int> last(26, -1);
        
        for(int i=0;i<n;i++){
            int idx1=s[i]-'a';
            int idx2=s[n-i-1]-'a';
            
            if(first[idx1]==-1) first[idx1]=i;
            if(last[idx2]==-1) last[idx2]=n-i-1;
        }
        
        int res=INT_MIN;
        
        for(int i=0;i<26;i++)
        {
            if(first[i]!=-1 && last[i]!=-1) res=max(res, last[i]-first[i]-1);
        }
        return res;
    }
};