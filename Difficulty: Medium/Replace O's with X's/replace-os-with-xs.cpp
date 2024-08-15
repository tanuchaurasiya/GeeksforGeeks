//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n, m;
    bool isValid(int i, int j){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>> &mat){
        mat[i][j]='-';
        
        
        if(isValid(i+1, j) && mat[i+1][j]=='O') dfs(i+1, j, mat);
        if(isValid(i, j+1) && mat[i][j+1]=='O') dfs(i, j+1, mat);
        if(isValid(i-1, j) && mat[i-1][j]=='O') dfs(i-1, j, mat);
        if(isValid(i, j-1) && mat[i][j-1]=='O') dfs(i, j-1, mat);
    }
    vector<vector<char>> fill(int N, int M, vector<vector<char>> mat)
    {
        n=N;
        m=M;
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O') dfs(0, i, mat);
        }
        
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='O') dfs(n-1, i, mat);
        }
        
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O') dfs(i, 0, mat);
        }
        
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O') dfs(i, m-1, mat);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O') mat[i][j]='X';
                else if(mat[i][j]=='-') mat[i][j]='O';
            }
        }
        
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends