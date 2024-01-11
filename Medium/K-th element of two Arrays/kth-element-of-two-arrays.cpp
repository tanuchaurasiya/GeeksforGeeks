//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    { 
        int i=0;
        int j=0;
        k--;
        while(k && i<n && j<m){
            if(arr1[i]>arr2[j]){
                j++;
                k--;
            }
            else if(arr1[i]<arr2[j]){
                i++;
                k--;
            } 
            else{
                if(k>=2){
                    i++;
                    j++;
                    k-=2;
                }
                else{
                    i++;
                    k-=1;
                }
            }
        }
        // cout<<"hi "<<i<<" "<<j<<" "<<k<<endl;
        if(k==0){
            if(i<n && j<m){
                if(arr1[i]>arr2[j]) return arr2[j];
                return arr1[i];
            }
            
            if(i<n) return arr1[i];
            return arr2[j];
        } 
            
        while(k && i<n) {
           i++;
           k--;
        }
        // cout<<"k="<<i<<endl;
        if(k==0) return arr1[i];
        
        while(k && j<m) {
           j++;
           k--;
        }
        if(k==0) return arr2[j];
        return -1;
        
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends