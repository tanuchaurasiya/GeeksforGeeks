//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int n, m;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[x][y] = true;  
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];  
            int ny = y + dy[dir]; 

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 'L' && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited);  
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();      
        m = grid[0].size();   

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    count++; 
                    dfs(i, j, grid, visited);  
                }
            }
        }

        return count;  
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends