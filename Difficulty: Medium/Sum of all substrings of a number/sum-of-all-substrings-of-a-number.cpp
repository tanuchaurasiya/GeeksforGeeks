class Solution {
  public:
    
    int sumSubstrings(string &s) {
        int n=s.length();
        int res=0;
        for(int i=0;i<n;i++){
            int num=0;
            for(int j=i;j<n;j++){
                num=num*10+(s[j]-'0');
                res+=num;
                // cout<<num<<endl;
            }
        }
        return res;
    }
};