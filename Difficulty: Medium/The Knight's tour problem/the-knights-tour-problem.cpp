class Solution {

  public:
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isSafe(int x, int y, int n, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }
    
    bool solve(int x, int y, int movei, int n, vector<vector<int>>& board) {
        if (movei == n * n) return true; // All cells visited
        
        for (int k = 0; k < 8; k++) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isSafe(nextX, nextY, n, board)) {
                board[nextX][nextY] = movei;
                if (solve(nextX, nextY, movei + 1, n, board))
                    return true;
                board[nextX][nextY] = -1; // Backtrack
            }
        }
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0; // Start position
        
        if (!solve(0, 0, 1, n, board))
            return {{-1}}; // No solution exists
        
        return board;
    }
};