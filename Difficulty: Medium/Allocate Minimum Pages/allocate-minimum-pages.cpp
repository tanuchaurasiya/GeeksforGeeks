//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    long long findPages(long long maxPage, int arr[], int n){
        long long stu=1;
        long long currPage=arr[0];
        
        int i=1;
        while(i<n){
            if(currPage+arr[i]<=maxPage){
                currPage+=arr[i];
            }
            else{
                stu++;
                currPage=arr[i];
            }
            i++;
        }
        return stu;
    }
    
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        long long low=INT_MIN;
        long long high=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>low) low=arr[i];
            high+=arr[i];
        }
        
        while(low<=high){
            long long mid = (low+high)/2;
            
            long long stu =  findPages(mid, arr, n);
            
            if(stu<=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends