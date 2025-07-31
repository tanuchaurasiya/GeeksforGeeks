class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> diff;
        for (auto &in : intervals) {
            diff[in[0]] += 1;
            diff[in[1] + 1] -= 1;
        }
        int curr = 0, ans = -1;
        auto it = diff.begin();
        while (it != diff.end()) {
            int start = it->first;
            curr += it->second;
            auto next_it = next(it);

            if (curr >= k && next_it != diff.end()) {
                ans = max(ans, next_it->first - 1);  
            }

            it = next_it;
        }

        return ans;
    }
};