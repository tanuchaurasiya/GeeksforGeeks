//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<vector<int>> dp;
    int n1;
    int n2;
    int findLCSLength(const std::string &text1, const std::string &text2, int index1, int index2) {
        if (index1 >= n1 || index2 >= n2) return 0;
        
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        
        if (text1[index1] == text2[index2]) {
            dp[index1][index2] = 1 + findLCSLength(text1, text2, index1 + 1, index2 + 1);
        } else {
            dp[index1][index2] = max(findLCSLength(text1, text2, index1, index2 + 1), findLCSLength(text1, text2, index1 + 1, index2));
        }
        return dp[index1][index2];
    }

    int findMinCost(string word1, string word2, int cost1, int cost2) {
        n1=word1.length();
        n2=word2.length();
        dp.resize(n1, vector<int>(n2,-1));
        int ret = findLCSLength(word1, word2, 0,0);
        return n1*cost1+n2*cost2 - (ret*cost1+ret*cost2);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends