class Solution {
  public:
    bool canFormPalindrome(string &s) {
        vector<int> v(26,0);
        
        for(int i=0;i<s.size();i++)
        {
            int idx = s[i]-'a';
            v[idx]++;
        }
        
        int odd=false;
        for(int i=0;i<26;i++)
        {
            if(v[i]%2 && odd) return false;
            if(v[i]%2) odd=true;
        }
        return true;
        
    }
};