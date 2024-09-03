//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        int i=n-1;
        sort(arr, arr+n);
        // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        // cout<<endl;
        while(i>=0){
            int j=i-1;
            int k=0;
            
            while(k<j){
                // cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
                if(arr[i]+arr[j]+arr[k]==0){
                    // cout<<"Res="<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    return true;
                }
                else if(arr[i]+arr[j]+arr[k]<0){
                    k++;
                }
                else {
                    j--;
                }
                
            }
            i--;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends