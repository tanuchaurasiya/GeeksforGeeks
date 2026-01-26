class Solution {
  public:
    void help(int i, int n, vector<int>&arr, vector<vector<int>>&res)
    {
        if(i==n) {res.push_back(arr); return;}
        for(int idx=i;idx<n;idx++)
        {
            swap(arr[i], arr[idx]);
            help(i+1,n,arr,res);
            swap(arr[i], arr[idx]);
        }
        return;
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        help(0, arr.size(), arr, res);
        return res;
    }
};