//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
  
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        int time=0;
        int freshOrange=0;
        queue<pair<pair<int,int>,int>>q;// to take rotten Oranges
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==1){
                    freshOrange++;
                }
                if(mat[i][j]==2){
                    q.push({{i,j},0});// insert all rottenOrange with 0 time
                }
            }
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=p.first.first;
            int c=p.first.second;
            int currTime=p.second;// for every rotten orange check time to rot orange
            time=max(currTime,time);// update time 
            for(int i=0;i<4;++i){
                int col=c+dy[i];
                int row=r+dx[i];
                if(col>=0 && col < m && row>=0 && row<n && mat[row][col]==1 ){
                    mat[row][col]=2;
                    freshOrange--;
                    q.push({{row,col},currTime+1});// increase currTime by one for that particular rot orange
                }
            }
            
        }
        if(freshOrange==0) return time;// if freshOrange is zero that means all had rottent
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends