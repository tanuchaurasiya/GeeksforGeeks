//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    typedef long long int P;
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // code here
        int n = nums.size();
        vector<P>left(n,1);
        vector<P>right(n,1);
        P lm = 1;
        P rm = 1;
        for(int i=1 ; i<n; i++){
            lm = lm*nums[i-1];
            left[i] = lm;
        }
        for(int i=n-2 ; i>=0 ; i--){
            rm = rm*nums[i+1];
            right[i] = rm;
        }
        vector<P>result;
        for(int i=0 ; i<n ; i++){
            result.push_back(left[i]*right[i]);
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends