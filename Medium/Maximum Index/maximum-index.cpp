//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int maxIndexDiff(int arr[], int n) 
    { 
       int mn[n], mx[n];
        mn[0] = arr[0];
        for(int i=1; i<n; i++){
            mn[i] = min(mn[i-1], arr[i]);
        }
        
        mx[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            mx[i] = max(mx[i+1], arr[i]);
        }
        
        // for(auto i:mn) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:mx) cout<<i<<" ";
        // cout<<endl;
        int i=0, j=0, ans=-1;
        while(i<n && j<n){
            if(mn[i] <= mx[j]){
                ans = max(ans, j-i);
                j += 1;
            }else{
                i += 1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends