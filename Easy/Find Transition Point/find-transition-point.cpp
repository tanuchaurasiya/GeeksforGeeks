//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    
    int transitionPoint(int a[], int n) {
        int s=0,e=n-1;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            if((a[mid]==1)&&(a[mid-1]==0)) return mid;
            
            else if(a[mid]==0) s=mid+1;
            
            else e=mid-1;
        }
         return -1;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends