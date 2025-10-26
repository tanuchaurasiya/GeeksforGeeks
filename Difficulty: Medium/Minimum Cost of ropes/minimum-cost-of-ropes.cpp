

class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        int n=arr.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(long long i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        long long res = 0;
        
        while(pq.size() > 1) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            
            res += (x + y);
            pq.push(x + y);
        }
        
        return res;
    }
};
