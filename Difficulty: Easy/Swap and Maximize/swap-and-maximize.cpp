//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int i=0;
        int j=arr.size()-1;
        
        long long ans=0;
        // 1 2 4 8
        int prev=0;
        while(i<j)
        {
            if(prev != 0)
            {
                ans+=abs(prev - arr[i]);
            }
            ans+=abs(arr[j] - arr[i]);
            prev=arr[j];
            i++;
            j--;
        }
        ans+=abs(prev - arr[0]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends