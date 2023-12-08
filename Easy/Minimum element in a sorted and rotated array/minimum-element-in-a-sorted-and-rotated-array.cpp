//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int l=0;
        int r=n-1;
        int minn=INT_MAX;
        while(l<=r){
            int mid =(l+r)/2; 
            // cout<<"l "<<arr[l]<<"mid="<<arr[mid]<<" r="<<arr[r]<<endl;
            if(arr[l]<=arr[mid]){
                minn = min(minn, arr[l]);
                l=mid+1;
            }
            else{
                minn = min(minn, arr[mid]);
                r=mid-1;
            }
        }
        return minn;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends