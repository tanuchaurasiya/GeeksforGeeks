class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> graph(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int t=edges[i][2];
            graph[u].push_back({t,v});
            graph[v].push_back({t,u});
        }
        
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        pq.push({0,0});
        int res=0;
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto child:graph[node])
            {
                int dis=child.first;
                int c=child.second;
                if(d+dis<dist[c])
                {
                    if(c==V-1) res=1;
                    dist[c]=d+dis;
                    pq.push({dist[c], c});
                }
                else if(d+dis==dist[c])
                {
                    if(c==V-1) res++;
                    pq.push({dist[c], c});
                }
            }
        }
        
        // cout<<"minDist="<<dist[V-1]<<endl;
        return res;
    }
};