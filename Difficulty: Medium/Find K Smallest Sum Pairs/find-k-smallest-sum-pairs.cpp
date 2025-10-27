class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int>> res;
        if(n1 == 0 || n2 == 0 || k == 0) return res;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        set<pair<int,int>> visited;
        minHeap.push({nums1[0] + nums2[0], 0, 0});
        visited.insert({0,0});

        while(k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int sum = top[0];
            int i = top[1];
            int j = top[2];

            res.push_back({nums1[i], nums2[j]});
            
            if(i + 1 < n1 && !visited.count({i + 1, j})) {
                visited.insert({i + 1, j});
                minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
            }

            if(j + 1 < n2 && !visited.count({i, j + 1})) {
                visited.insert({i, j + 1});
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        
        return res;
    }

};
