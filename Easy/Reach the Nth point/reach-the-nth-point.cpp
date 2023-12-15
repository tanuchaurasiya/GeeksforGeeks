//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int nthPoint(int n){
    
    int M = 1e9+7;
    long long prev2 = 1, prev1 = 1;
  
    for(int i = 2; i <= n; i++){
      
        long long ans = (prev2 + prev1) % M;
        
        prev2 = prev1;
        
        prev1 = ans;
    
    }
  
    return prev1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends