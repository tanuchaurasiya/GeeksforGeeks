//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string help(string s, int n)
    {
        if(n==1) return s;

        int i=0;
        int count=0;
        int c=s[0];
        int size=s.size();

        string s1="";

        while(i<s.size())
        {
            while(i<size && s[i]==c) {
                count++;
                i++;
            }
            s1+=count+'0';
            s1+=c;
            count=0;
            c=s[i];
        }
        // cout<<s1<<endl;
        return help(s1,n-1);
    }
    string countAndSay(int n) {
        return help("1", n);
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends