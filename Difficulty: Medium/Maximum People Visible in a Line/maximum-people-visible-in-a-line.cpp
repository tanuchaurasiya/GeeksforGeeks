class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n,0),next(n,n),prev(n,-1);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
         for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int l=prev[i],r=next[i];
            maxi=max(maxi,r-l-1);
        }
        return maxi;
        
    }
};