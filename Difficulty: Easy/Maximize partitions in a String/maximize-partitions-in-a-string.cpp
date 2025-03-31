//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char,int> first, last;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(first.count(s[i])==0)
            {
                first[s[i]]=i;
            }

            last[s[i]]=i;
        }

        int i=n-1,j=n-1;
        int res=0;
        while(j>=0)
        {
            if(first[s[j]]==last[s[j]] && i==j) res++;

            else{
                i=first[s[j]];
                int idx=j;
                while(i<j)
                {
                    j--;
                    if(i>first[s[j]]){
                        i=first[s[j]];
                    }
                }
                res++;
            }
            j--;
            i--;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends