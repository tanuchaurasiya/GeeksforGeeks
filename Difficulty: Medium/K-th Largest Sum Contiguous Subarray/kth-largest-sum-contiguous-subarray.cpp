//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0 ;i<arr.size();i++){
            int sum = 0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(pq.empty() || pq.size()<k){
                    pq.push(sum);
                }
                else if(!pq.empty() && pq.size()>=k && pq.top()<sum){
                    pq.pop();
                    pq.push(sum);
                }
              
            }
        }
        return pq.top();
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends