class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &pathVisited, vector<int> &visited)
    {
        visited[node]=1;
        pathVisited[node]=1;
        for(auto child: adj[node])
        {
            if(!visited[child]){
                if(dfs(child, adj, pathVisited,visited)) return true;
            }
            else if(pathVisited[child]) return true;
        }
        pathVisited[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> visited(V);
        vector<int> pathVisited(V);
        vector<vector<int>> adj(V);
        
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
           
        }
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]) continue;
            if(dfs(i, adj, pathVisited, visited)) return true;
        }
        
        return false;
        
    }
};