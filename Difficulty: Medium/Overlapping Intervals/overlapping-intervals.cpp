class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        auto temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(temp[0] <=intervals[i][0] && temp[1]>=intervals[i][0])
            {
                temp = {temp[0], max(temp[1], intervals[i][1])};
            }
            else{
                res.push_back(temp);
                temp=intervals[i];
                
            }
        }
        res.push_back(temp);
        return res;
    }
};