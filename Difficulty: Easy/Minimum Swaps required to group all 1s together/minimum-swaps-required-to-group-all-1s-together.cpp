//{ Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n);

// Driver Code
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << minSwaps(a, n) << endl;
    }

    return 0;
}

// } Driver Code Ends


int minSwaps(int arr[], int n) {
    int c=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) c++;
    }
    if(c==0) return -1;
    int zero=0;
    int i=0;
    while(i<c){
        if(arr[i]==0) zero++;
        i++;
    }
    
    int res=zero;
    while(i<n){
        if(arr[i-c]==0) zero--;
        if(arr[i]==0) zero++;
        res=min(res, zero);
        i++;
    }
    return res;
}