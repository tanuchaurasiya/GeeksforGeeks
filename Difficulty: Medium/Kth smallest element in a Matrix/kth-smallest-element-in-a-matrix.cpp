class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int low = mat[0][0], high = mat[n-1][n-1];
        while(low <= high) {
            int mid = (high + low) / 2;
            if(countHelper(mat, mid) < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    int countHelper(vector<vector<int>> &mat, int mid) {
        int count = 0, row = 0, col = mat[0].size()-1;
        while(row < mat.size() && col >= 0) {
            if(mat[row][col] <= mid) {
                count += (col + 1);
                row++;
            } else col--;
        }
        return count;
    }
   
};
