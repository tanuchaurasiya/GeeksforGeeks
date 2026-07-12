class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        
        int res=0;
        int MOD = 1e9 + 7;
        while(k)
        {
            int x=pq.top();
            if(x<0) return res;
            res=(res+x)%MOD;
            pq.pop();
            pq.push(x-1);
            k--;
        }
        return res;
    }
};