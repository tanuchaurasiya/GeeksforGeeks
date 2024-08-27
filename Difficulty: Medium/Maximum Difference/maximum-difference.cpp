//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> rightSmaller(n);
        vector<int> leftSmaller(n);
        
        stack<int> st;
        
        int i=0;
        while(i<n){
            if(st.empty()) {
                st.push(arr[i]);
                leftSmaller[i]=0;
            }
            else{
                while(!st.empty() && st.top()>=arr[i]){
                    st.pop();
                }
                
                if(st.empty()) leftSmaller[i]=0;
                else leftSmaller[i] = st.top();
                st.push(arr[i]);
            }
            i++;
        }
        
        while(!st.empty()) st.pop();
        i=n-1;
        
        while(i>=0){
            if(st.empty()) {
                st.push(arr[i]);
                rightSmaller[i]=0;
            }
            else{
                while(!st.empty() && st.top()>=arr[i]){
                    st.pop();
                }
                
                if(st.empty()) rightSmaller[i]=0;
                else rightSmaller[i] = st.top();
                st.push(arr[i]);
            }
            i--;
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            res=max(res, abs(leftSmaller[i]-rightSmaller[i]));
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends