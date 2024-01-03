//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int z=-1,o=-1,t=-1;
        int n=S.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            if(S[i]=='1'){
                o=i;
            }
            if(S[i]=='0'){
                z=i;
            }
            if(S[i]=='2'){
                t=i;
            }
            if(z>-1&&o>-1&&t>-1){
                ans=min(ans,max(max(z,o),t)-min(min(z,o),t)+1);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends