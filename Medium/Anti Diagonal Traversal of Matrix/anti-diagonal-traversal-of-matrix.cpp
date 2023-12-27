//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> res; 
        unordered_map<int, vector<int>> mp; 
        int maxSum = 0; 
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                maxSum = max(maxSum, i+j); 
                mp[i+j].push_back(matrix[i][j]);
            }
        } 
        
        for(int i=0;i<=maxSum;i++){
            for(auto item:mp[i]) 
                res.push_back(item);
        } 
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends