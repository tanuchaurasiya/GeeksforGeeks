//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	    void help(int i, string temp, vector<string> &res, string s, int n){
	        if(i==n) {
	            res.push_back(temp);
	            return ;
	        }
	        
	        if(s[i]=='?'){
	            help(i+1, temp+'0', res, s, n);
	            help(i+1, temp+'1', res, s, n);
	        }
	        else{
	            help(i+1, temp+s[i], res, s, n);
	        }
	    }
		vector<string> generate_binary_string(string s)
		{
		     int n=s.length();
		     int i=0;
		     vector<string> res;
		     help(i, "", res, s, n);
		     return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends