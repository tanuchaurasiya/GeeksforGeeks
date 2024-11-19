//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
    void Findpermutation(vector<int>& a, int n){
        int idx=-1;
        for(int i = n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                idx=i;
                break;
            }
        }
        
        if(idx==-1){
            reverse(a.begin(), a.end());
            return;
        }
        
        for(int i=n-1;i>idx;i--){
            if(a[i]>a[idx]) 
            {
                int temp = a[i];
                a[i]=a[idx];
                a[idx] = temp;
                break;
            }
        }
        reverse(a.begin()+idx+1, a.end());
        return;
        
       
    }
   
    void nextPermutation(vector<int>& a) {
        int N = a.size();
        Findpermutation(a,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends