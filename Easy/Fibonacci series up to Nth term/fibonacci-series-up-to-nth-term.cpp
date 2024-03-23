//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = 1e9+7;

    vector<int> Series(int n) {
        vector<int> fibo(n+1, 0);
        fibo[1] = 1;
        
        for(int i = 2;i <= n; i++)
            fibo[i] = (fibo[i-1]+fibo[i-2])%mod;
            
        return fibo;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends