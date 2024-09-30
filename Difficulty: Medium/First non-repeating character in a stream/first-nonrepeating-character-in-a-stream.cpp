//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int> v(26,0);
		    string res="";
		    for(int i=0;i<A.length();i++){
		        int idx = A[i]-'a';
		        if(v[idx]==0) {
		            v[idx]=i+1;
		        }
		        else{
		            v[idx]=-1;
		        }
		        int minn=INT_MAX;
		        for(int j=0;j<26;j++){
		            if(v[j]>0) minn=min(minn, v[j]);
		        }
		        
		        if(minn==INT_MAX) res+="#";
		        else res+=A[minn-1];
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends