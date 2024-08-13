//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string res="";
    int reslen=0;
    
    bool subseq(int i, int j, int n1, int n2, string s, string w){
        if(j==n2) return true;
        if(i==n1) return false;
        
        if(s[i]==w[j]){
            return subseq(i+1, j+1, n1, n2, s, w);
        }
        
        return subseq(i+1, j, n1, n2, s, w);
    }
    string findLongestWord(string S, vector<string> d) {
        int n1=S.length();
        for(auto w:d){
            int len=w.length();
            if(subseq(0, 0, n1, len, S, w)){
                if(reslen<len){
                    res=w;
                    reslen=len;
                }
                if(reslen==len){
                    if(res>w){
                       res=w;
                    }
                }
            }
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
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++)
            cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends