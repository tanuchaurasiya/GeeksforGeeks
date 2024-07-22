//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    
    int binarySearch(vector<int>& temp, int target) {
        int low = 0;
        int high = temp.size() - 1;
        int mid;
        int idx;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (target <= temp[mid]) {
                if(target==temp[mid]) idx=mid;
                high = mid - 1;
            }
           
            else if (target > temp[mid]) {
                low = mid + 1;
            }
        }
        return idx;
    }
    vector<int> constructLowerArray(vector<int>& arr) {
        vector<int> temp=arr;
        int n = arr.size();
        vector<int> res(n);
        sort(temp.begin(), temp.end());

        for(int i=0;i<n;i++){
            int idx = binarySearch(temp, arr[i]);
            res[i]=idx;
            temp.erase(temp.begin()+idx);
        }
        return res;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends