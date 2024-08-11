//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int currtime = 0;
    int c;
    int d;
    int dfs(int node, int parent, vector<int> graph[], vector<int> &visited, vector<int> &time, vector<int> &low){
        visited[node]=1;
        time[node] = currtime;
        low[node] = currtime;
        currtime++;
        for(auto child: graph[node]){
            if(child==parent) continue;
            if(!visited[child]) 
            {
                if (dfs(child, node, graph, visited, time, low)) 
                    return 1;
                low[node] = min(low[node], low[child]);
                if(low[child] > time[node]){
                    if((child==c && node==d) || (child==d && node==c)) {
                        return 1;
                    }
                }
            }
            else{
                low[node] = min(low[node], low[child]);
            }
        }
        return 0;

    }
    int isBridge(int n, vector<int> graph[], int c1, int d1) 
    {
        
        int node=0;
        int parent=-1;
        currtime=0;
        vector<int> visited(n,0);
        vector<int> time(n,0);
        vector<int> low(n,0);
        c=c1;
        d=d1;
        for(int i=0;i<n;i++){
            if(dfs(i, -1, graph,visited, time, low)) return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends