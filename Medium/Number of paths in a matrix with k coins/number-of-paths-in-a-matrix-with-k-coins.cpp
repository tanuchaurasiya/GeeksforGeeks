//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int solve(int i,int j,int k, vector<vector<int>> &arr){
        if(i>=arr.size() || j>=arr.size()){
            return 0;
        }
        if(i==(arr.size()-1) && i==j ){
            return k==arr[i][j];
        }
        if(k<0){
            return 0;
        }
        if(i<0 || j<0){
            return 0;
        }
        
        int down=solve(i+1,j,k-arr[i][j],arr);
        int right=solve(i,j+1,k-arr[i][j],arr);
        return down + right ;
    }
    
    int solveDP(int i,int j,int k, vector<vector<int>> &arr,vector<vector<vector<int>>>& dp){
        if(i>=arr.size() || j>=arr.size()){
            return 0;
        }
        if(i==(arr.size()-1) && i==j ){
            return k==arr[i][j];
        }
        if(k<0){
            return 0;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int down=solveDP(i+1,j,k-arr[i][j],arr,dp);
        int right=solveDP(i,j+1,k-arr[i][j],arr,dp);
        return dp[i][j][k] = down + right ;
    }
    
    
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        // return solve(0,0,k,arr);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return solveDP(0,0,k,arr,dp);
        
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends