//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n=arr1.size();
        
        int low=0;
        int high=n;
        
        while(low<=high)
        {
            int mid1=(low+high)/2;
            
            int mid2=(n)-mid1;
            
            int left1=INT_MIN;
            int left2=INT_MIN;
            int right1=INT_MAX;
            int right2=INT_MAX;
            
            if(mid1>0)
            {
                left1=arr1[mid1-1];
            }
            if(mid2>0)
            {
                left2=arr2[mid2-1];
            }
            if(mid1<n)
            {
                right1=arr1[mid1];
            }
            if(mid2<n)
            {
                right2=arr2[mid2];
            }
            if(right2<left1)
            {
                high=mid1-1;
            }
            else if(right1<left2)
            {
                low=mid1+1;
            }
            else
            {
                int sum=max(left1,left2)+min(right1,right2);
                return sum;
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends