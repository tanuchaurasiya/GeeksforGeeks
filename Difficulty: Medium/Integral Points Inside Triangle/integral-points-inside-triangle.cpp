//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        long long int A=abs((p[0]*(q[1]-r[1]) + q[0]*(r[1]-p[1]) + r[0]*(p[1]-q[1]))/2);
        long long int B1 =__gcd(abs(p[0]-q[0]),abs(p[1]-q[1]))+1;
        long long int B2 =__gcd(abs(q[0]-r[0]),abs(q[1]-r[1]))+1;
        long long int B3 =__gcd(abs(r[0]-p[0]),abs(r[1]-p[1]))+1;
        long long int B=(B1+B2+B3-3)/2;
        return (A-B+1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends