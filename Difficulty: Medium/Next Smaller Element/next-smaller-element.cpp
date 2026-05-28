class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse(n,-1);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(arr[i]);
                continue;
            }
            while(!st.empty() && arr[i]<=st.top()) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(arr[i]);
        }
        return nse;
        
    }
};