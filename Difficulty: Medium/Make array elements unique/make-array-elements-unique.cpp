//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int num=arr[0];
        int ans=0;
        
        int i=1;
        int n=arr.size();
        // 1 2 5 6 6 8 9 9 9
        while(i<n){
            if(num>=arr[i] ){
                while(i<n && num>=arr[i]) {
                    num++;
                    ans+=(num-arr[i]);
                    i++;
                }
            }
            else{
                num=arr[i];
                i++;
            }
            
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
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends