class Solution {
  public:
    int findMinDiff(vector<int>& arr, int m) {
        int n=arr.size();
        if (m == 0 || n == 0)
        return 0;
 
        sort(arr.begin(), arr.end());
        if (n < m)
            return -1;
        long long min_diff = INT_MAX;
     
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
        
    }
};