//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long ans=0;
    void merge(long long arr[], long long low, long long mid, long long high){
        long long n1 = mid-low+1; 
        long long n2 = high-mid;
        long long a1[n1];
        long long a2[n2];
        for(long long i=0;i<n1;i++){
            a1[i] = arr[low+i];
        }
        
        for(long long i=0;i<n2;i++){
            a2[i] = arr[mid+1+i];
        } 
        
        long long k = low;
        long long i =0;
        long long j=0;
        
        while(i<n1 && j<n2){
            if(a1[i]>a2[j]){ 
                ans+=(n1-i);
                arr[k] = a2[j];
                j++;
                k++;
            }
            
            else if(a1[i]<=a2[j]){
                arr[k] = a1[i];
                i++;
                k++;
            }
            
            // else{
            //     arr[k] = a1[i];
            //     k++;
            //     i++;
            //     arr[k] = a2[j];
            //     k++;
            //     j++;
            // }
        }
        
        while(i<n1){
            arr[k] = a1[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k] = a2[j];
            j++;
            k++;
        }
        
    }
    void mergeSort(long long arr[], long long low, long long high){
        if(low<high){
            long long mid = (low+high)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        ans=0;
        mergeSort(arr, 0, N-1);
        return ans;
    }
    
    
    
    
    
    
    
    
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends