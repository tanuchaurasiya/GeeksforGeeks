//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> graph(N);
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> res(N, INT_MAX);
        pq.push({0, src});
        while(!pq.empty()){
            int d = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            res[n]=d;
            for(auto child:graph[n]){
                if(res[child] > d+1){
                    res[child] = d+1;
                    pq.push({d+1, child});
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(res[i]==INT_MAX) res[i]=-1;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends