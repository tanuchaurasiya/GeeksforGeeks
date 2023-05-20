//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
    public:
    vector<vector<int>> mergeInterval(vector<vector<int>> intervals)
    {
        vector <int>tmp{intervals[0][0], intervals[0][1]};
        
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){

            if (tmp[0] <= intervals[i][0] && intervals[i][0]<= tmp[1]){
                tmp = {tmp[0],max(intervals[i][1],tmp[1])};
            }
            else{
                ans.push_back(tmp);
                tmp = {intervals[i][0], intervals[i][1]};
            }
        }
        ans.push_back(tmp);
        return ans;
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(),range.end()); 
        vector<int> res;
        
        
        vector<vector<int>> ans=mergeInterval(range);
        // for(auto v: ans){
        //     for(auto x:v) 
        //         cout<<x<< " ";
        //     cout<<endl;
        // }
        for(auto k:queries){
            bool flag=0;
            for(auto v: ans){
                // cout<<v[0]<< " "<<k-1<<" "<<v[1]<<endl;
                if(v[0]+(k-1)<=v[1]){
                   res.push_back(v[0]+k-1);
                   flag=1;
                   break;
               }
                else
                    k=k-(v[1]-v[0]+1);
                
            } 
            if (flag==0)
                res.push_back(-1);
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
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends