//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int nums[], int n) {
        int i=0;
        vector<int> maxArray(n,INT_MIN);
        int currMax=INT_MIN;
        for(int i=n-1;i>=0;i--){
            currMax=max(currMax, nums[i]);
            maxArray[i]=currMax;
        }

        // for(auto i:maxArray) cout<<i<<" ";
        // cout<<endl;

        int res=0;

        for(int i=0;i<n;i++){
            int l = i+1;
            int h = n-1;

            while(l<=h){
                int m = (l+h)/2;
                // cout<<l<<" "<<h<<" "<<m<<endl;
                if(maxArray[m]>=nums[i]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            // cout<<"end="<<l<<" "<<h<<endl;
            res=max(res, l-i-1);
        }
        return res;
    }

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends