//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findMinPoint( int i,int j, int m,int n,vector<vector<int>> &points, vector<vector<int>> &dp)
 {
     if(i==m-1&&j==n-1)
     return (points[i][j]>0?0:-points[i][j]+1);
     
     if(i>=m|| j>=n)
     return 1000000009;
     
     if(dp[i][j]!=-1) return dp[i][j];
     int x1= findMinPoint(i+1,j,m,n,points,dp);
     int x2= findMinPoint(i,j+1,m,n,points,dp);
     
     int ans= points[i][j]-min(x1,x2);
     
     if(ans>0)
     return dp[i][j]=0;
     
     if(min(x1,x2)==0)
     return dp[i][j]= -ans+1;
     
     return dp[i][j]= -ans;
     
 }
    int minPoints(int m, int n, vector<vector<int>> points) 
    { 
       
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = findMinPoint(0, 0, m, n, points, dp);
        if(ans==0) return 1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends