class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> res;
        int i=0;
        int l=1;
        int n=arr.size();
        while(i<n)
        {
            vector<int> temp;
            for(int j=0;j<l && i<n;j++){
                temp.push_back(arr[i]);
                i++;
            }
            l=2*l;
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};
