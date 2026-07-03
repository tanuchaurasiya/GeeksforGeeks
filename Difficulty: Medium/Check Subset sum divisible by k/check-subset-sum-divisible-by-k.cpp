class Solution {
  public:
    bool help(int i, vector<int>& arr, int& k, int &n, int sum, vector<vector<int>>& vec){
        if(sum!=0 && sum%k==0) return true;
        
        if(i==n) return false;
        
        if(vec[i][sum%k]!=-1) return vec[i][sum%k];
        
        if(help(i+1, arr, k, n, sum+arr[i],vec)) return vec[i][sum%k]=true;
        if(help(i+1, arr, k, n, sum, vec)) return vec[i][sum%k]=true;
        return vec[i][sum%k]=false;
    }
    bool divisibleByK(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> vec(n, vector<int>(k,-1));
        return help(0, arr, k, n, 0, vec);
    }
};