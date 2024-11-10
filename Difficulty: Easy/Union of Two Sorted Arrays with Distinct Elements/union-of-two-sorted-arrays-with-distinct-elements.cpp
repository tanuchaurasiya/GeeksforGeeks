//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n=a.size(),m=b.size(),s1=0,s2=0;
        vector<int>ans;
        while(s1<n && s2<m){
            if(a[s1]==b[s2]){
                ans.push_back(a[s1]);
                s1++;
                s2++;
            }
            else if(a[s1]<b[s2]){
                ans.push_back(a[s1]);
                s1++;
            }
            else {
                ans.push_back(b[s2]);
                s2++;
            }
        }
        while(s1<n){
            ans.push_back(a[s1]);
            s1++;
        }
        while(s2<m){
            ans.push_back(b[s2]);
            s2++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends