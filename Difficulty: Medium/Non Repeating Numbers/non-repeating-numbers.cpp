//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorAll=0;
        for(auto x:nums){
            xorAll^=x;
        }
        
        int rightMost=0;
        int set1=0;
        int set2=0;
        while(!(xorAll>>rightMost & 1)){
            rightMost++;
        }
        
        
        for(auto x:nums){
            if((x>>rightMost) &1) {
                set1^=x;
            }
            else set2^=x;
        }
        if(set1>set2) return {set2, set1};
        return {set1, set2};
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends