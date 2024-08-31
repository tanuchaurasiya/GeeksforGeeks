//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>> dp;
    bool help(int i, int tar, vector<int>arr){
        if(tar==0) return true;
        
        if(i==0){
            if(arr[0]==tar) return true;
            return false;
        }
        
        if(dp[i][tar]!=-1) return dp[i][tar];
        
        bool nottake = help(i-1, tar, arr);
        
        bool take=false;
        if(arr[i]<=tar){
            take = help(i-1, tar-arr[i], arr);
        }
        
        return dp[i][tar] = take | nottake;
    }
    bool isSubsetSum(vector<int>arr, int tar){
        int n = arr.size();
        dp.resize(n, vector<int>(tar+1,-1));
        return help(n-1,tar, arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends