//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
long long mod=1e9+7;
long long f(int s,int n,int k,long long &ans){
    if(k>n)return 0;
    
    int m=1;
    int e=s+k-1;
   for(int i=s;i<=e;i++)m=((m%mod)*(i%mod)%mod)%mod;
   k++;
   
  ans= m+f(e+1,n,k,ans);
   return ans%mod;
}
    long long sequence(int n){
        long long ans=1;
       f(1,n,1,ans); 
       return ans;// code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends