class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> res(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()){st.push(arr[i]); continue;}
            while(!st.empty() && st.top()<=arr[i])
            {
                st.pop();
            }
            if(!st.empty()) res[i]=st.top();
            st.push(arr[i]);
        }
        return res;
    }
    
};