//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int>v(n,-1);
        for(int i=0;i<n;i++){
            if(gallery[i]!=-1){
                int left = max(0,i-gallery[i]);
                int right = min(n-1,i+gallery[i]);
                for(int j=left;j<=right;j++){
                    v[j]=max(v[j],right);
                }
            }
        }
        int count =0;
        int curr=-1;
        for(int i=0;i<n;i++){
            if(v[i]==-1){
                return -1;
            }
            if(i>curr){
                count++;
                curr=v[i];
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends