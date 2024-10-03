//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int m=l;
        
        while(m<=h){
            if(arr[m]==0){
                swap(arr[m], arr[l]);
                m++;
                l++;
            }
            else if(arr[m]==2){
                swap(arr[m], arr[h]);
                h--;
            }
            else{
                m++;
            }
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends