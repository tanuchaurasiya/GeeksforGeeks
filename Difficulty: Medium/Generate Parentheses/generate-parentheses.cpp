//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    int n;
    vector<string> res;
    void help(int i, string temp, int left, int right){
        if(i==n) {
            res.push_back(temp);
            return;
        }

        if(left<n/2){
            help(i+1, temp+"(", left+1, right);
        }

        if(right<left){
            help(i+1, temp+")", left, right+1);
        }
    }
    vector<string> AllParenthesis(int N) {
        n=N*2;
        help(0, "", 0, 0);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends