// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int len=0;
        int ans=-1;
        int m=arr.size();
        int n=arr[0].size();
        int j=n-1;
        for(int i=0;i<m;i++){
           while(j>=0&&arr[i][j]==1){
               j--;
           }
           if(n-j-1>len){
               ans=i;
               len=n-j-1;
           }
        }
        return ans;
        
    }
};