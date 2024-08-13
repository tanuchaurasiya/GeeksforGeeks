//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1>n2){
            return MedianOfArrays(arr2, arr1);
        }
        int low=0;
        int high=n1;
        int midIdx=(n1+n2+1)/2;
        while(low<=high)
        {
            int mid1 = (low+high)/2;
            int mid2 = midIdx-mid1;
            
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            
            if(mid1>0){
                l1=arr1[mid1-1];
            }
            
            if(mid2>0){
                l2=arr2[mid2-1];
            }
            
            if(mid1<n1){
                r1=arr1[mid1];
            }
            
            if(mid2<n2){
                r2=arr2[mid2];
            }
            
            if(l1>r2){
                high=mid1-1;
            }
            
            else if(l2>r1){
                low=mid1+1;
            }
            
            else{
                if((n1+n2)%2==0){
                    return (double(double(max(l1,l2))/2) + double(double(min(r1,r2))/2));
                }
                return double(max(l1,l2));
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends