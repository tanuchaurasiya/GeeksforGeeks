//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

int countNoOfPairWithDiffLessThanOrEqualToK(int nums[], int k,int n)
    {
        int res = 0;
        int l=0;
        for(int r=0;r<n;r++){
            while(nums[r]-nums[l]>k)
                l++;
            res+=r-l;
        }
        return res;
    }
    int kthDiff(int nums[], int n, int k)
    {
        sort(nums, nums+n);
        int low=0;
        int high=nums[n-1];
        int count;
        while(low<=high){
            int mid = (low+high)/2;

            count = countNoOfPairWithDiffLessThanOrEqualToK(nums,mid,n);

            if(count>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    
    }