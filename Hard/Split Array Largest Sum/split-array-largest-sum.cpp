//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    pair<int,int> help(int arr[], int n, int maxsum){
        int i=1;
        int count=1; 
        int currsum=arr[0];
        int maxSum=arr[0];
        while(i<n){
            if(currsum+arr[i]<=maxsum){
                currsum+=arr[i];
                i++;
            }
            else{
                maxSum=max(maxSum, currsum);
                count++;
                currsum=arr[i];
                i++;
            }
        }
        maxSum=max(maxSum, currsum);
        return {count, maxSum};
    }
    int splitArray(int arr[] ,int N, int K) { 
        int i=0;
        int sum=0;
        while(i<N){
            sum+=arr[i];
            i++;
        }
        int low = 0;
        int high = sum;
        int res=INT_MAX;
        while(low<=high){
            int mid = (low+high)/2; 
            pair<int,int> p= help(arr, N, mid); 
            int count = p.first;
            int maxsum = p.second;
            // cout<<"low="<<low<<" high="<<high<<endl;
            // cout<<"mid="<<mid<<" count="<<count<<" maxsum="<<maxsum<<endl;
            
            if(count<=K) {
                res=min(res, maxsum);
                high = mid-1;
            }
                
            else
                low = mid+1;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends