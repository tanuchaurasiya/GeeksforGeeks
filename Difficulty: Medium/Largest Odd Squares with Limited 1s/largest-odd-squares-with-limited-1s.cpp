class Solution {
  public:
    int getSum(vector<vector<int>>& pref,
               int top, int left,
               int bottom, int right) {

        int sum = pref[bottom][right];

        if (top > 0)
            sum -= pref[top - 1][right];

        if (left > 0)
            sum -= pref[bottom][left - 1];

        if (top > 0 && left > 0)
            sum += pref[top - 1][left - 1];

        return sum;
    }

    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k){

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                pref[i][j] = mat[i][j];

                if (i > 0)
                    pref[i][j] += pref[i - 1][j];

                if (j > 0)
                    pref[i][j] += pref[i][j - 1];

                if (i > 0 && j > 0)
                    pref[i][j] -= pref[i - 1][j - 1];
            }
        }

        int q = queries.size();
        vector<int> res(q, -1);

        for (int x = 0; x < q; x++) {

            int r = queries[x][0];
            int c = queries[x][1];

            int ans = -1;

            for (int d = 0; ; d++) {

                int top = r - d;
                int bottom = r + d;
                int left = c - d;
                int right = c + d;

                if (top < 0 || bottom >= n ||
                    left < 0 || right >= m)
                    break;

                int ones = getSum(pref, top, left, bottom, right);

                if (ones > k)
                    break;

                ans = 2 * d + 1;
            }

            res[x] = ans;
        }

        return res;
    }
};