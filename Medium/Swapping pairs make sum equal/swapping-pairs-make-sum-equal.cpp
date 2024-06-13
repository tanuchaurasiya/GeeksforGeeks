//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int s1=0;
        int s2=0;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++){
            s1+=a[i];
        }
        
        for(int j=0;j<m;j++){
            s2+=b[j];
            mp2[b[j]] = 1;
        }
        if(s1==s2) return 1;
        for(int i=0;i<n;i++){
            auto x = (s2-s1)/2 + a[i]; 
            if((s2-s1)%2==0 && mp2[int(x)]!=0) return 1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends