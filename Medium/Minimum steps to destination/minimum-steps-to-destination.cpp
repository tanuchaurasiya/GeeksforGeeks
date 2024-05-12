//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        int stepValue =1 ; 
        int stepNo =0 ;
        int value = 0 ;
        while(value<d || (value-d) %2!=0)
        {  value = value + stepValue ; 
           stepValue++ ; 
           stepNo++ ;
        }
       return stepNo ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends