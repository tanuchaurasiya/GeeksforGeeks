class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        unordered_map<int,int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,start});
        visited[start]=0;
        
        int res=INT_MAX;
        
        while(!pq.empty()){
            int step=pq.top().first;
            int val=pq.top().second;
            pq.pop();
            
            // cout<<step<<" "<<val<<endl;
            
            if(val==end) {
                res=min(res, step);
                continue;
            }
            
         
            for(auto mult:arr){
                int x=(mult*val)%1000;
                if(!visited[x]){
                    visited[x]=1;
                    pq.push({step+1, x});
                }
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};