//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: input array
    // Function to find the maximum index difference.
    int maxIndexDiff(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }

        int res=0;
        for(int i=n-1;i>=0;i--){
            while((!st.empty()) && nums[i] >= nums[st.top()]){
                res=max(res, i-st.top());
                st.pop();
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}
// } Driver Code Ends