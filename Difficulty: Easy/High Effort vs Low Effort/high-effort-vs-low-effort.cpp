class Solution {
    private:
    int perform_task(vector<int> &h, vector<int> &l, int index, bool visited, vector<vector<int>> &dp){
        if(index>=h.size()){
            return 0;
        }
        if(dp[index][visited]!=-1)return dp[index][visited];
        int a=0, b=0, c=0;
       
        a= 0 + perform_task(h, l, index+1, 0, dp);
        b= l[index] + perform_task(h, l, index+1,1, dp);
        if(index==0 or !visited){
            c=  h[index] + perform_task(h, l, index+1, 1, dp);
        }
        return dp[index][visited]= max(a, max(b, c));
        
    }
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        vector<vector<int>>dp(h.size(), vector<int>(2, -1));
         return perform_task(h, l, 0, 0, dp);
         
    }
};