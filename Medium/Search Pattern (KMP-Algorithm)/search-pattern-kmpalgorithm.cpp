//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void computeLPS(vector<int> &arr,int n,string pat){
            int len=0;
            int i=1;
            arr[0]=0;
            while(i<n){
                if(pat[i]==pat[len]){
                    arr[i]=len+1;
                    len++,i++;
                }
                else{
                    if(len!=0) {
                        len=arr[len-1];
                    }
                    else{
                        arr[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> ans;
            int n=txt.length();
            int m=pat.length();
            vector<int> lps(m,0);
            computeLPS(lps,m,pat);
            int i=0,j=0;
            while(i<n){
                if(txt[i]==pat[j]){
                    i++,j++;
                }
                else{
                    if(j!=0) j=lps[j-1];
                    else i++;
                }
                if(j==m) {
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
            }
            return ans;
        }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends