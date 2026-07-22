class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        vector<int>vec;
        for(auto it : arr){
            if(!vec.size() || it> vec.back()){
                vec.push_back(it);
                continue;
            }
            int ind = lower_bound(vec.begin(), vec.end(), it) - vec.begin();
            vec[ind] = it;
        }
        return arr.size() - vec.size();
    }
};