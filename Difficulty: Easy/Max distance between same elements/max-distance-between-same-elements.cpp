//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            left[arr[n-i-1]]=n-i-1;
            right[arr[i]] = i;
        }
        int ans=0;
        for(auto i:arr){
            ans=max(ans, right[i]-left[i]);
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
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends