//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long
class Solution{
    public:
    vector<vector<int>> dp;
    long long help(int i, int j, int arr[])
    {
        if(i>j)
        return 0;
        
        if(dp[i][j]!=-1 ) return dp[i][j];
    
        ll a=arr[i]+min(help(i+2,j,arr),help(i+1,j-1,arr));
        ll b=arr[j]+min(help(i,j-2,arr),help(i+1,j-1,arr));
        
        dp[i][j] = max(a,b);
        return dp[i][j];
         
    }
    long long maximumAmount(int n, int arr[]){
       dp.resize(n, vector<int>(n,-1));    
       return help(0, n-1, arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends