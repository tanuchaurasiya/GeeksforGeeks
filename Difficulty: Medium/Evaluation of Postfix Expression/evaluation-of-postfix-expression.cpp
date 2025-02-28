//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int a, int b, char op){
        switch(op) {
        case '+' : return a+b; break;
        case '-' : return a-b; break;
        case '*' : return a*b; break;
        case '/' : return a/b; break;
        }
    }
    int evaluate(vector<string>& arr) {
       
       int n=arr.size();
       
       stack<int> st;
       
       for(int i=0;i<n;i++){
           if(isdigit(arr[i][0]) || (arr[i][0]=='-' && isdigit(arr[i][1]))) st.push(stoi(arr[i]));
           else{
               int b=st.top();
               st.pop();
               int a=st.top();
               st.pop();
               int val=solve(a,b,arr[i][0]);
               st.push(val);
           }
       }
       
       return st.top();
       
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends