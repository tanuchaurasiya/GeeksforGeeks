//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int help(int i, int W, vector<int>& wt, vector<int>& val, int n){
        if(i>=n)
            return 0; 
        
        if(W==0) 
            return 0;
        int take = INT_MIN;
        int nottake INT_MIN;
        if(wt[i]<= W){ 
            take = val[i]+help(i+1, W-wt[i], wt, val, n); 
        }
            
        nottake =help(i+1, W, wt, val, n);  
      
        return max(take, nottake);
        
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
       return help(0, W, wt, val, n);
    }
    
    
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends