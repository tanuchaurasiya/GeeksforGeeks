//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   pair<bool, long long> solve( string s ) {
       long long num = 0;
       long long ten=1;
        for( long long i = s.length()-1; i >=0; i-- ) {
            if( (!isdigit( s[i] )) || (s[i]-'0')==9 ) {
               return {false,-1};
        }
        num=num+(s[i]-'0')*ten;
        ten*=10;
   }
   return {true, num};
}
    long long ExtractNumber(string sentence) {

        istringstream ss(sentence);
        string word; 
        long long res=-1;
        while (ss >> word) {
           auto p = solve(word);
           if(p.first==true) res=max(res, p.second);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends