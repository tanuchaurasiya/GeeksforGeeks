//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod = 1e9+7;
    int padovanSequence(int n) {
        int x0 = 1;
        int x1 = 1;
        int x2 = 1;
        
        if(n<3) return 1;
        int x;
        for(int i=3;i<=n;i++){
            x = (x1 + x0)%mod;
            x0=x1;
            x1=x2;
            x2=x;
        }
        return x;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends