//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int find(vector<int> &union_find, int ind) {
        while(union_find[ind] != ind)
            ind = union_find[ind];
        return ind;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<int> union_find(accounts.size(), 0);
        unordered_map<int, vector<string>> res_map;
        for (int i = 0; i < accounts.size(); i++) {
            union_find[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) != m.end()) {
                    int root1 = find(union_find, i);
                    int root2 = find(union_find, m[accounts[i][j]]);
                    union_find[root1] = root2;
                }
                else
                    m[accounts[i][j]] = union_find[i];
            }
        }
        for (auto it : m) {
            int ind = find(union_find, it.second);
            res_map[ind].push_back(it.first);
        }
        vector<vector<string>> res;
        for (auto it : res_map) {
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            res.push_back(email);
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
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends