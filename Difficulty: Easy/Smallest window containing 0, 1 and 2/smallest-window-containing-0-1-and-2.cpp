class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int n=s.size();
        
        int zero=0;
        int one=0;
        int two=0;
        
        int res=INT_MAX;
        
        while(i<n)
        {
            if(s[i]=='0') {
                zero++;
            }
            if(s[i]=='1') {
                one++;
            }
            if(s[i]=='2') {
                two++;
            }
            
            while(one && two && zero)
            {
                res=min(res, i-j+1);
                if(s[j]=='0') zero--;
                if(s[j]=='1') one--;
                if(s[j]=='2') two--;
                j++;
            }
            
            i++;
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};
