//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void permutation(int idx, int k, string& num, string& res, int n)
    {
        if (k == 0 || idx == n)
        {
            res = max(res, num);
            return;
        }
        char maxDigit = *max_element(num.begin() + idx, num.end());

        for (int i = idx; i < n; ++i)
        {
            if (num[i] == maxDigit)
            {
                if (i != idx) {
                    swap(num[i], num[idx]);
                    permutation(idx + 1, k - 1, num, res, n);
                    swap(num[i], num[idx]);  
                } else {
                    permutation(idx + 1, k, num, res, n);
                }
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        string res = s;
        permutation(0, k, s, res, s.size());
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends