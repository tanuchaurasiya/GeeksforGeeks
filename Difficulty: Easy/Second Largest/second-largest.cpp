//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();

        // Initialize variables to track the largest and second largest values
        int largest = 0;
        int secondLargest = 0;
    
        // Loop through the array
        for (int i = 0; i < n; i++) {
            // If the current element is greater than the largest,
            // update secondLargest to the current largest and then update largest
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            // If the current element is smaller than the largest but greater than secondLargest,
            // update secondLargest
            else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
    
        // If secondLargest remains 0, it means no second largest element exists
        // (e.g., when all elements are the same or the array has fewer than 2 elements)
        return secondLargest == 0 ? -1 : secondLargest;

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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends