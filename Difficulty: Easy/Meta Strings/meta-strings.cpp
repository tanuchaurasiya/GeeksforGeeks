//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string s1, string s2)
{
    int i1=-1;
    int i2=-1;
    if(s1.length()!=s2.length()) return false;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            if(i1!=-1 && i2!=-1) return false;
            else if(i1==-1) i1=i;
            else{
                i2=i;
            }
        }
    }
    if(i1==-1 || i2==-1) return false;
    if(s1[i1]==s2[i2]) return true;
    return false;
}