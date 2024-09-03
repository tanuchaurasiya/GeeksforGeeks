//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int X, int Y) {
        if(grid[0][0]==0) return -1;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
           
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
           
            if(row == X && col == Y) return cost;
           
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(ncol >= 0 && ncol < m && nrow >= 0 && nrow < n && (grid[nrow][ncol]==1) && dist[nrow][ncol] > cost+1) {
                    dist[nrow][ncol] = cost + 1;
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends