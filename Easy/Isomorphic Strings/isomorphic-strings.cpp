//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
        if(s1.length()!=s2.length()) return false;
         unordered_map<char, char> mp;
         unordered_map<char, char> mp1;
        for(int i=0;i<s1.length();i++){
            bool x = (mp.find(s1[i]) == mp.end());
            bool y = (mp1.find(s2[i]) == mp1.end());
            
            if( x ==true && y==true){
                mp[s1[i]] = s2[i];
                mp1[s2[i]] = s1[i];
            }
            
            
            else if(x==true && y==false){
                return false;
            }
            else{
                if(mp[s1[i]]!=s2[i])  return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends