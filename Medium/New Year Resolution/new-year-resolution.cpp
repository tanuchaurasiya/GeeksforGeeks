//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
   int help(int coins[], int n, int j, int sum) {
        if(sum != 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024)) return 1;
        if(j == n) return 0;
        int pick = help(coins, n, j+1, sum+coins[j]);
        if(pick == 1) return 1;
        int notPick = help(coins, n, j+1, sum);
        return pick || notPick;
    }
    public:
    int isPossible(int n, int coins[]) {
        return help(coins, n, 0, 0);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends