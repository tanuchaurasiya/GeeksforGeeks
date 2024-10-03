//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int countb=0;
        string sb="";
        while(b){
            if(b%2) {
                sb="1"+sb;
                countb++;
            }
            else sb="0"+sb;
            b=b/2;
        }
        
        string sa="";
        int counta=0;
        int res=a;
        while(a){
            if(a%2){
                sa="1"+sa;
                counta++;
            }
            else
               sa="0"+sa;
            a=a/2;
        }
        // cout<<"sa="<<sa<<" sb="<<sb<<endl;
        if(countb==counta) return res;
        
        while(sa.length() > sb.length()){
            sb="0"+sb;
        }
        
        while(sa.length() < sb.length()){
            sa="0"+sa;
        }
            
        // cout<<"sa="<<sa<<" sb="<<sb<<endl;
        // cout<<"counta="<<counta<<" countb="<<countb<<endl;
        if(counta > countb){
            int i=sa.length()-1;
            while(counta > countb){
                if(sa[i]=='1') {
                    sa[i]='0';
                    counta--;
                }
                i--;
            }
            // cout<<"59 sa="<<sa<<endl;
        }
        else{
            int i=sa.length()-1;
            while(counta < countb){
                if(sa[i]=='0') {
                    sa[i]='1';
                    counta++;
                }
                i--;
            }
            // cout<<"70 sa="<<sa<<endl;
        }
        res=0;
        int x=0;
        for(int i=sa.length()-1;i>=0;i--){
            if(sa[i]=='1') res+=pow(2,x);
            x++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends