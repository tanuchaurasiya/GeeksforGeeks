//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        int temp[26];
        memset(temp,0,sizeof temp);
        int x=0,y=0;
        for(int i=0; i<s.size(); i++){
            temp[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if((i+1)%2){
                if(temp[i]%2)y++;
            }
            else{
                if(temp[i]%2==0 and temp[i]!=0){
                    x++;
                }
            }
        }
        return (x+y)%2==1?"ODD":"EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends