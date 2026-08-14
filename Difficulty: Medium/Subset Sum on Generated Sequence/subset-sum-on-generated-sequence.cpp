class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int target) {
        long long sum = s;
        vector<int> res;
        res.push_back(s);

        for (int a : arr) {
            long long old = sum;
            sum += a;
            res.push_back(sum);
            sum += old;
        }

        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] <= target) {
                target -= res[i];
            }

            if (target == 0)
                return true;
        }

        return false;
        
    }
};