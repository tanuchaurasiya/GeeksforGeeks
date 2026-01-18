class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int,int> freq;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) 
            {
                st.push(arr[i]);
                res[i]=-1;
            }
            else{
                while((!st.empty()) && (freq[st.top()]<=freq[arr[i]])) st.pop();
                if(!st.empty()) res[i]=st.top();
                else res[i]=-1;
                st.push(arr[i]);
            }
        }
        return res;
    }
};
