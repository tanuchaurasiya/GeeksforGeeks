class Solution {
  public:
    int findLength(vector<int> &c, vector<int> &r) {
        // code here
        int n=c.size();
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({c[i], r[i]});
            }
            else{
                if(st.top().first==c[i] && st.top().second==r[i]) st.pop();
                else st.push({c[i], r[i]});
            }
        }
        return st.size();
    }
};