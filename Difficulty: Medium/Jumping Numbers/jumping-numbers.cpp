//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long num) {
        long long res=0;
        queue<long long> q;
        
        for(long long i=1;i<=9;i++){
            q.push(i);
        }
        
        while(!q.empty())
        {
            long long x = q.front();
            q.pop();
            if(x>num) continue;
            
            if(x>res) res=x;
            
            long long lastdigit = x%10;
            
            if(lastdigit!=0) {
                q.push(x*10 + lastdigit-1);
            }
            if(lastdigit!=9) {
                q.push(x*10 + lastdigit+1);
            }
            
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends