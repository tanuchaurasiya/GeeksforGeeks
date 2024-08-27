//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends

class Solution {
public:
    unordered_map<char,char> mp1;
    unordered_map<char,char> mp2;
    bool areIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        if(n1!=n2) return false;

        int i=0;
        int j=0;
        
        while(i<n1){

            if(mp1.find(s[i])==mp1.end() && mp2.find(t[i])==mp2.end()){
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }

            else if(!(mp1[s[i]]==t[i]) || (!mp2[t[j]]==s[i])) return false;

            i++;
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