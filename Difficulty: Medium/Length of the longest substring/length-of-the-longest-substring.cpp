//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int l=0;
        int r=0;
        int res=0;
        vector<int> v(26,0);
        while(r<s.length()){
            int idx = s[r]-'a';

            if(v[idx]==0) v[idx]++;
            else{
                while(v[idx]!=0){
                    v[s[l] - 'a']--;
                    l++;
                }
                v[idx]++;
            }
            // cout<<"l="<<l<<" r="<<r<<endl;
            res=max(res, r-l+1);
            r++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends