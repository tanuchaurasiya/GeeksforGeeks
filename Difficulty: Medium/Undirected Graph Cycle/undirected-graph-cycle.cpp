class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, int par, vector<int> &visited)
    {
        visited[node]=1;
        for(auto child: adj[node])
        {
            if(!visited[child]){
                if(dfs(child, adj, node,visited)) return true;
            }
            else{
                if(child!=par) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> visited(V);
        vector<vector<int>> adj(V);
        
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]) continue;
            if(dfs(i, adj, -1, visited)) return true;
        }
        
        return false;
    }
};