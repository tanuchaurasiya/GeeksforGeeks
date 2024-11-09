//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to add two large numbers represented as strings
    string addStrings(const string &num1, const string &num2) {
        string result = "";
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
    
        reverse(result.begin(), result.end());
        return result;
    }
    
    // Helper function to remove leading zeros
    string removeLeadingZeros(const string &str) {
        int i = 0;
        while (i < str.size() && str[i] == '0') {
            i++;
        }
        return (i == str.size()) ? "0" : str.substr(i);
    }
    
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        if (n == 1) return to_string(arr[0]);
        
        int i = 0;
        int j = 1;
        
        string sum1 = "";
        string sum2 = "";
        
        while (i < n && j < n) {
            sum1 += to_string(arr[i]);
            sum2 += to_string(arr[j]);
            i += 2;
            j += 2;
        }
        
        if (i < n) {
            sum1 += to_string(arr[i]);
        }
        
        // Add sum1 and sum2 as large numbers represented by strings
        string result = addStrings(sum1, sum2);
        return removeLeadingZeros(result);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends