//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string res=arr[0];
        int maxc=arr[0].length();
       
        for(int i=1;i<arr.size();i++){
            int c = 0;
            for(int j=0;j<arr[i].length();j++){
                if(j<maxc && arr[i][j]==res[j]){
                    c++;
                }
                else{
                    break;
                }
            }
            if(c==0) return "-1";
            else if(maxc>c){
                maxc=c;
                res=arr[i].substr(0, c);
                // cout<<"res="<<res<<" c="<<c<<endl;
            }
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
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends