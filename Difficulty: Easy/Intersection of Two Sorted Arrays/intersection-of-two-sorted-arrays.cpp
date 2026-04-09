class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
vector<int> ans;
        int i = 0, j = 0;
        
        while (i < a.size() && j < b.size()){
            if (a[i] < b[j]) i++;
            else if (a[i] > b[j]) j++;
            else {
                if (ans.empty() || ans.back() != a[i]) 
                    ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};