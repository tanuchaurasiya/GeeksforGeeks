//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> v1;
        
        
        int i=0,j=0; 
    
        
        while(i<n && j<m){ 
            while(i<n-1 && arr1[i] == arr1[i+1]) {
                i++; 
            }
            
            while(j<m-1 && arr2[j] == arr2[j+1]) {
                j++; 
            }
            
            if(arr1[i]<arr2[j]){
                v1.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j]){
                v1.push_back(arr2[j]);
                j++;
            }
            else{
                v1.push_back(arr2[j]);
                j++;
                i++;
            }
            
        }
      
        while(i<n){ 
            while(i<n-1 && arr1[i] == arr1[i+1]) 
                i++;
            v1.push_back(arr1[i]);
            i++;
        }
        while(j<m){
            while(j<m-1 && arr2[j] == arr2[j+1]) 
                j++;
            
            v1.push_back(arr2[j]);
            j++;
    }    
    
       return v1; 
    
    }
};



//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends