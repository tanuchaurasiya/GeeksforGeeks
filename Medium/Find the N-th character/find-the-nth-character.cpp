//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     char nthCharacter(string s, int r, int n) {
        while(r--){
            string res = "";
            for(char ch : s){
                if(ch == '1'){
                    res += "10";
                }
                else{
                    res += "01";
                }
            }
            s = res.substr(0,n+1);
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends