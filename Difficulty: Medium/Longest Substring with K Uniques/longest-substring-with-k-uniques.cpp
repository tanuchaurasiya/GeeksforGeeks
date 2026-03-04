class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<int,int>m;
        int i = 0;
        int j = 0;
        int n = s.size();
        int length = -1;
        while(j < n){
            
            m[s[j]]++;
            
            if(m.size() > k){
                if(m[s[i]]==1){
                    m.erase(s[i]);
                }
                else{
                    m[s[i]]--;
                }
                i++;
            }
            
            if(m.size()==k){
                length = max(length,j-i + 1);
            }
            
            j++;
            
        }
        return length;
    }
};