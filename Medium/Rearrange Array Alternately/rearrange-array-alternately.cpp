//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
     void rearrange(long long *arr, int n) 
    { 
    	int lastidx=n-1;
    	int firstidx=0;
    	int maxi=arr[n-1]+1;
    	for(int i=0;i<n;i++)
    	{
    	    if(i%2==0)
    	    {
    	        arr[i]+=(arr[lastidx]%maxi)*maxi;
    	        lastidx--;
    	    }
    	    else
    	    {
    	    arr[i]+=(arr[firstidx]%maxi)*maxi;
    	        firstidx++;
    	    }
    	}
    	for(int i=0;i<n;i++)
    	arr[i]/=maxi;
    	 
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends