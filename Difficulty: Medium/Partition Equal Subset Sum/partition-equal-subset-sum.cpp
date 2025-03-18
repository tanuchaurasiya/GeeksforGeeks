//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int help(int i, int sum, vector<int>& arr, int tar , int n, vector<unordered_map<int,int>> &dp){
        // cout<<sum<<endl;
        if(sum==tar) 
            return 1;
        if(i>=n || sum>tar)
            return 0; 
        // cout <<dp[i][sum]<<endl;
        if(dp[i].find(sum) != dp[i].end())
           return dp[i][sum];
           
        int a = help(i+1, sum+arr[i],arr, tar, n, dp);
        int b = help(i+1,sum, arr, tar, n, dp);
        dp[i][sum] = a || b;
        return dp[i][sum];
        
    }
   
    int equalPartition(vector<int>& nums)
    {
        int n=nums.size();
        int summ=0;
        for(int i=0;i<n;i++) summ+=nums[i];
        
        if(summ%2) return 0;
        vector<unordered_map<int,int>> dp(n);
        return help(0, 0, nums,summ/2,n, dp);
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends