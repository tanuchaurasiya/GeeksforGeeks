//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        int open=0;
        int close=0;
        int res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open++;
            else close++;
            if(close>open) {
                open=0;
                close=0;
            }
            else{
                if(open==close) res=max(res, open);
            }
        }
        open=0;
        close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(close<open) {
                open=0;
                close=0;
            }
            else
                if(open==close) res=max(res, open);
        }
        return res*2;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends