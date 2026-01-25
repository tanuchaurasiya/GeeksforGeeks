class Solution {
  public:
    bool isValid(string s)
    {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) st.push(s[i]);
            else{
                if(s[i]==')' && st.top()=='(') st.pop();
                else st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        return false;
        
    }
    void generate(int i, string s, int& n, int& res, int open, int close)
    {
        if(i==n) {
            if(open==close && isValid(s)) {
                res++;
            }
            return;
        }
        
        generate(i+1, s+'(', n, res, open+1, close);
        generate(i+1, s+')', n, res, open, close+1);
    }
    int findWays(int n) {
        int i=0;
        int res=0;
        generate(i, "", n, res, 0, 0);
        return res;
        
    }
};