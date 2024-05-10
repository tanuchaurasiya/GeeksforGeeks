//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class Solution {
  public:
    void help(int i, int sum, vector<vector<int>> &res, vector<int> &temp, vector<int>& candidates, int target, int n){
        if(sum==target)
        {
            res.push_back(temp);
            return;
        }
        if(sum>target || i>=n)
            return;
        
        // cout<<i<<" "<<sum<<endl;
        temp.push_back(candidates[i]);
    
        help(i+1, sum+candidates[i], res,temp, candidates, target, n);
        
        while(i+1 < n &&candidates[i] == candidates[i+1]) i++;
        temp.pop_back(); 
        help(i+1, sum, res,temp, candidates, target, n);
    }
   vector<vector<int>> CombinationSum2(vector<int> candidates,int n,int target){
        vector<vector<int>> res;
        vector<int> temp; 
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        help(0, 0, res, temp, candidates, target, n);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends