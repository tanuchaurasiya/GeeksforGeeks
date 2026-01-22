class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
         int n = arr.size();
        stack<int> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int x = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                ans-=(arr[x]*(x-l)*(i-x));
            }
            st.push(i);
        }
        while(!st.empty()){
            int x = st.top();
            st.pop();
            int l = st.empty() ? -1 : st.top();
            ans-=(arr[x]*(x-l)*(n-x));
        }
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                int x = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                ans+=(arr[x]*(x-l)*(i-x));
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int x = st.top();
            st.pop();
            int l = st.empty() ? -1 : st.top();
            ans+=(arr[x]*(x-l)*(n-x));
        }
        
        return ans;

    }
};