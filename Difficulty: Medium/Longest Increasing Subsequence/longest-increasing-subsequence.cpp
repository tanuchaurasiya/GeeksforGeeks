//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,int prev,vector<int>& arr,vector<vector<int>> &dp){
        if(i==arr.size())
        return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int pick=0;
        if(prev==-1 || arr[i]>arr[prev])
        pick = 1 + solve(i+1,i,arr,dp);
        
        int notPick = solve(i+1,prev,arr,dp);
        
        return dp[i][prev+1] = max(pick,notPick);
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
    //   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //   return solve(0,-1,arr,dp);  

          vector<vector<int>> dp(n+1,vector<int>(n+1,0));

          for(int i=n-1;i>=0;i--){
              for(int prev=i-1;prev>=-1;prev--){
                    int pick=0;
            if( prev==-1 || arr[i]>arr[prev])
            pick = 1 + dp[i+1][i+1];
        
            int notPick = dp[i+1][prev+1];
            dp[i][prev+1] = max(pick,notPick);
              }
          }
           
          return dp[0][0];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends