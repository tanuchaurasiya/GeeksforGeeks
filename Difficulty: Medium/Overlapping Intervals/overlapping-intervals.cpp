//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        auto temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(temp[0] <=intervals[i][0] && temp[1]>=intervals[i][0])
            {
                temp = {temp[0], max(temp[1], intervals[i][1])};
            }
            else{
                res.push_back(temp);
                temp=intervals[i];
                
            }
        }
        res.push_back(temp);
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends