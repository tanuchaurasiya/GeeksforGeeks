//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int k = n - 1; k >= 2; k--)
        {
            int i = 0;
            int j = k - 1;
            while (i < j)
            {
                int sum = arr[i] + arr[j];
                if (sum == arr[k])
                {
                    return true;
                }
                else if (sum < arr[k])
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends