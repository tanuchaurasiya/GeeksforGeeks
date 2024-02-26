//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(string s, int i, string si,vector<string>&vec){
	        if(i==s.size()){
	            if(si!=""){
	                vec.push_back(si);
	            }
	            return;
	        }
	        solve(s,i+1,si+s[i],vec);
	        solve(s,i+1,si,vec);
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string>vec;
		    solve(s,0,"",vec);
		    sort(vec.begin(),vec.end());
		    return vec;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends