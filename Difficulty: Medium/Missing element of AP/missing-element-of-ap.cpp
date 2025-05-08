//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int d;
        if(n == 2) {
            d = arr[1] - arr[0];
        } else {
            if(arr[1] - arr[0] < 0) {
                d = max(arr[1] - arr[0], arr[2] - arr[1]);
            } else {
                d = min(arr[1] - arr[0], arr[2] - arr[1]);
            }
        }
        int a=arr[0];
        n++;
        long long sn = (2*a)+(n-1)*d;
        sn=sn*n;
        sn=sn/2;
        
        long long s=0;
        // cout<<sn<<endl;
        for(auto i:arr) s+=i;
        
        return sn-s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends