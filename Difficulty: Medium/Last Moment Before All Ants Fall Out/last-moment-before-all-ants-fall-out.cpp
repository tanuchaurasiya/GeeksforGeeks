class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int res=INT_MIN;
        
        for(int i=0;i<left.size();i++){
            res=max(res, left[i]);
        }
        
        for(int i=0;i<right.size();i++){
            res=max(res, n-right[i]);
        }
        return res;
    }
};