//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int M=1e9+7;
    int sumSubarrayMins(int n, vector<int> &arr) {
        vector<int> rightSmaller(n);
        vector<int> leftSmaller(n);
        
        stack<pair<int,int>> st;
        
        int i=0;
        while(i<n){
            if(st.empty()) {
                st.push({arr[i],i});
                leftSmaller[i]=-1;
            }
            else{
                int val;
                int idx;
                while(!st.empty()){
                    val=st.top().first;
                    idx = st.top().second;
                    if(val>=arr[i]) st.pop();
                    else{
                        break;
                    }
                }
                
                if(st.empty()) leftSmaller[i]=-1;
                else leftSmaller[i] = idx;
                st.push({arr[i], i});
            }
            i++;
        }
        
        while(!st.empty()) st.pop();
        i=n-1;
        
        while(i>=0){
            if(st.empty()) {
                st.push({arr[i],i});
                rightSmaller[i]=n;
            }
            else{
                int val;
                int idx;
                while(!st.empty()){
                    val=st.top().first;
                    idx = st.top().second;
                    if(val>arr[i]) st.pop();
                    else{
                        break;
                    }
                }
                
                if(st.empty()) rightSmaller[i]=n;
                else rightSmaller[i] = idx;
                st.push({arr[i], i});
            }
            i--;
        }
        
        // for(auto c:leftSmaller) cout<<c<<" ";
        // cout<<endl;
        
        // for(auto c:rightSmaller) cout<<c<<" ";
        // cout<<endl;
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            long long l=i-leftSmaller[i];
            long long r=rightSmaller[i]-i;
            long long m=(l%M * r%M) % M;
            ans=(ans + (arr[i] * m) % M) % M;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends