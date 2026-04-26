class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &graph, unordered_map<int,int> &visited, int parent)
    {
        visited[node]=1;
        for(auto child:graph[node])
        {
            if(visited[child]){
                if(child!=parent) return true;
                continue;
            }
            
            if(dfs(child,graph, visited, node)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        unordered_map<int,int> visited;
        
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0){
                if(dfs(i, graph, visited, -1)) return true;
            } 
        }
        return false;
        
    }
};