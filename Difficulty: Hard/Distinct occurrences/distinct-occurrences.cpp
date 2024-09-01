//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int mod = 1e9+7;
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1)); 
        
        for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }

        for(int j=0;j<=n1;j++){
            dp[j][0]=1;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int x =0;
                int y =0;
                if(s[i-1]==t[j-1]) {
                    x = dp[i-1][j-1];
                    y = dp[i-1][j];
                }
                else{   
                    y = dp[i-1][j];
                }
                dp[i][j] = (x+y)%mod;
            }
        }
        return dp[n1][n2];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends