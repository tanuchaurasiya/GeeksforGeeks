class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int,  vector<int>, greater<int>> pq;
        int n=arr.size();
        vector<int> res(n);
        
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size()<k){ res[i]=-1; continue;}
            if(pq.size()>k) pq.pop();
            res[i]=pq.top();
            
        }
        return res;
        
    }
};