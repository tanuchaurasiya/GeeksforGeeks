//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &arr) {
        stack<int> q;
        q.push(arr[0]);
        
        for(int i=1;i<n;i++){
            if(!q.empty() && (q.top()>0 && arr[i]<0)){
                // cout<<"q="<<q.top()<<" arr="<<arr[i]<<endl;
                int flag=0;
                while(!q.empty() && (q.top()>0 && arr[i]<0)){
                    int t1=abs(q.top());
                    int t2=abs(arr[i]);
                    // cout<<"t1="<<t1<<" t2="<<t2<<endl;
                    if(t1==t2){
                        q.pop();
                        flag=0;    
                        break;
                    }
                    else if(t1<t2){
                        q.pop();
                        flag=1;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
                if(flag) q.push(arr[i]);
                
            }
            else{
                q.push(arr[i]);
                // cout<<"size="<<q.size()<<endl;
            }
        }
        
        vector<int> res;
        
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends