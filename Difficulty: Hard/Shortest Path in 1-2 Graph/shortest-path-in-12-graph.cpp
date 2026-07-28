class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({src,0});
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto e:edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        while(!pq.empty())
        {
            int node=pq.top().first;
            int dis=pq.top().second;
            pq.pop();
            
            for(auto child:adj[node])
            {
                int nc=child.first;
                int nd = child.second;
                
                if(dist[nc]>dis+nd){
                    dist[nc]=dis+nd;
                    pq.push({nc, dist[nc]});
                }
            }
            
        }
        if(dist[dest]==INT_MAX) return -1;
        return dist[dest];
    }
};