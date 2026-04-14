class Solution {
  public:
    string removeSpaces(string& s) {
        string res="";
        for(int i=0;i<s.length();i++) 
        {
            if(s[i]!=' ') res+=s[i];
        }
        return res;
    }
};