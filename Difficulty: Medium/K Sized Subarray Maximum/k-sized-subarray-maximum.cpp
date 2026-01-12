class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < k; i++)
            q.push({arr[i], i});
            
        ans.push_back(q.top().first);
        for(int i = 1; i < n-k+1; i++ ){
            while(!q.empty() && q.top().second < i){
                q.pop();
            }
            
            q.push({arr[i+k-1], i+k-1});
            ans.push_back(q.top().first);
        }
        return ans;  
    }
};