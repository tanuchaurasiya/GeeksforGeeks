//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.length(); 
        if(n==1 || n==2){
            if(stoi(s) % 8 ==0) return 1;
            return -1;
        }
        
        string temp="";
        for(int i=n-1; i>n-4;i--){
            temp=s[i]+temp;
        }
       
        if(stoi(temp) % 8 ==0) return 1;
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends