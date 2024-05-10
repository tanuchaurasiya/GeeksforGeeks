//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        int sum=0;
        int res=0;
        unordered_map<int,int> prefixsum; 
        for(int i=0;i<N;i++)
            {
                sum+=A[i]; 
                // cout<<sum<< " "<<sum-k<<" "<<prefixsum[sum-k]<<endl;
                if(sum==k)
                    res=max(res, i+1); 
                if(prefixsum.find(sum-k)!=prefixsum.end())
                    res=max(res, i-prefixsum[sum-k]);
                
                if(prefixsum.find(sum)==prefixsum.end())
                    prefixsum[sum] = i;
            }
        return res;
    } 

};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends