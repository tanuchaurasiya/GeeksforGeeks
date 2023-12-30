//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        int max = INT_MIN;
        map<string,int> mp;
        vector<string> ans;
        string temp_str = "";
        string temp_int = "";
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr->second > max)
            {
                max = itr->second;
                temp_str = itr->first;
                temp_int = to_string(itr->second);
            }
        }
        ans.push_back(temp_str);
        ans.push_back(temp_int);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends