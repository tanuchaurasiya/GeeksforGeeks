//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool sortingFunc(const pair <int,int> &a,const pair <int,int> &b){
        return (a.second == b.second)? a.first < b.first : a.second > b.second;  
    }
    vector<int> sortByFreq(vector<int>& arr) {
        vector <pair <int,int>> me;
        vector <int> ans;
        map <int,int> mp;
        for(int e:arr)mp[e]++;
        for(auto e:mp)me.push_back(make_pair(e.first,e.second));
        sort(me.begin(),me.end(),sortingFunc);
        for(auto e:me)if(e.second>=1)for(int i=0;i<e.second;i++)ans.push_back(e.first);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends