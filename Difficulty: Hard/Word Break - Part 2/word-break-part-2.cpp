//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> res;
    void help(int i, string temp, string final, string A, vector<string> &B, int n){ 
        // cout<<temp<<endl;
        if(i==n){
            if(temp=="") {
                res.push_back(final);
                return;
            }
            if(find(B.begin(), B.end(), temp)!=B.end()){
                if(final!="") final+=" "+temp;
                else final+=temp;
                res.push_back(final);
            }
                
            return ;
        }
        
        if(find(B.begin(), B.end(), temp)!=B.end()){
            if(final=="") help(i, "", final+temp, A, B, n);
            else help(i, "", final+" "+temp, A, B, n);
        }
        
        
        help(i+1, temp+A[i], final, A, B, n);
       
    }
    
    vector<string> wordBreak(int n, vector<string>& B, string A)
    {
        help(0, "", "", A, B,A.length());
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends