//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
        int totalSum=0;
        for(int i=0;i<n;i++) totalSum+=arr[i];
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(totalSum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if(arr[0]<=totalSum) dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int t=1;t<=totalSum;t++){
                bool nottake = dp[i-1][t];
                bool take=false;
                if(arr[i]<=t){
                    take = dp[i-1][t-arr[i]];
                }
                
                dp[i][t] = take | nottake;
            }
        }

        int res = INT_MAX;
        for(int sub1=0;sub1<=totalSum;sub1++){
            if(dp[n-1][sub1]==true){
                int sub2=totalSum-sub1;
                res=min(res, abs(sub1-sub2));
            }
        }
        return res;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends