//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        long long a[n][10];
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                a[i][j]=0;
                if(i==0) a[i][j]=1;
            }
        }
        if(n==1) return 10;
        for(int i=1;i<n;i++){
            a[i][0]=a[i-1][0]+a[i-1][8];
            a[i][1]=a[i-1][1]+a[i-1][2]+a[i-1][4];
            a[i][2]=a[i-1][2]+a[i-1][1]+a[i-1][3]+a[i-1][5];
            a[i][3]=a[i-1][3]+a[i-1][2]+a[i-1][6];
            a[i][4]=a[i-1][4]+a[i-1][1]+a[i-1][5]+a[i-1][7];
            a[i][5]=a[i-1][5]+a[i-1][2]+a[i-1][4]+a[i-1][6]+a[i-1][8];
            a[i][6]=a[i-1][6]+a[i-1][3]+a[i-1][5]+a[i-1][9];
            a[i][7]=a[i-1][7]+a[i-1][4]+a[i-1][8];
            a[i][8]=a[i-1][8]+a[i-1][5]+a[i-1][7]+a[i-1][9]+a[i-1][0];
            a[i][9]=a[i-1][9]+a[i-1][6]+a[i-1][8];
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            ans+=a[n-1][i];
        }
        return ans;
        
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends