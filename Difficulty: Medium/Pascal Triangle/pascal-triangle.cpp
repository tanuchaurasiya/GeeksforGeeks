//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
       if(n==1)
            return {1};
        if(n==2)
            return {1,1};
        vector<int> l{1,1};
        for(int i=2;i<n;i++){ 
            vector<int> l1;
            l1.push_back(1); 
            int j=0;
            while(j<i-1){
                l1.push_back((l[j]+l[j+1])%1000000007);
                j+=1;
            }
            l1.push_back(1);
            l = l1;
       
        }
        return l;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends