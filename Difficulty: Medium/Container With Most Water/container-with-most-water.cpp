//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int n)
{
    long long l=0;
    long long r=n-1;

    long long res=0;

    while(l<r){
        res=max(res, (r-l)*min(height[l], height[r]));
        if(height[l]>height[r]){
            r--;
        }
        else{
            l++;
        }
    }
    return res;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends