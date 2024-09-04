//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int> countForT;
    int n;
    bool isSubstringExist(string& s, int size, string& curr){
        vector<int> temp(26);
        int i=0;
        
        while(i<size){
            int idx = s[i]-'a';
            temp[idx]++;
            i++;
        }
        int j=0;
        
        while(j<26) {
            if(temp[j]<countForT[j]){
                break;
            }
            j++;
        }
        if(j==26){
            curr=s.substr(0, size);
            return true;
        }
        
        // cout<<"22="<<s.substr(0, size)<<endl;
        if(temp==countForT) {
            curr=s.substr(0, size);
            return true;
        }

        while(i<n){
            int idx = s[i]-'a';
            int prev = s[i-size]-'a';
            temp[prev]--;
            temp[idx]++;
            int j=0;
            while(j<26) {
                if(temp[j]<countForT[j]){
                    break;
                }
                j++;
            }
            if(j==26){
                // cout<<"i="<<i<<endl;
                curr=s.substr(i-size+1, size);
                return true;
            }
            i++;
        }
        return false;
        
    }
    string smallestWindow (string s, string t){
        n=s.size();
        countForT.resize(26);
        for(int i=0;i<t.size();i++){
            int idx = t[i]-'a';
            countForT[idx]++;
        }
        int l=0;
        int h=s.size();

        string res="-1";
        // isSubstringExist(s, 3, res);
        
        while(l<=h){
            int mid=(l+h)/2;
            // cout<<l<<" "<<h<<" "<<mid<<endl;
            string curr="";

            if(isSubstringExist(s, mid, curr)){
                // cout<<"mid="<<mid<<" "<<curr<<endl;
                h=mid-1;
                res=curr;
            }
            else{
                l=mid+1;
            }
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
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends