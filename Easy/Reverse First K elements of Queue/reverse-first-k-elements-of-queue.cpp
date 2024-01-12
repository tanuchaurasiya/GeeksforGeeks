//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    queue<int> modifyQueue(queue<int> q, int k) {
        int n=q.size();
        stack<int> temp;
        
        for(int i=0;i<k;i++){
            temp.push(q.front());
            q.pop();
        }
        
        while(temp.size()>0){
            q.push(temp.top());
            temp.pop();
        }

        // queue now stores remaining n-k elements in the front, which are then moved to their original position


        for(int i=0;i<n-k;i++){
            int el=q.front();
            q.pop();
            q.push(el);
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends