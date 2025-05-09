//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<char> st;
        int i=0;
        string res="";
        while(i<s.length()){
            if(s[i]==']'){
                string temp;
                while(st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                int num = 0;
                int x=0;
                while((!st.empty()) && (!(st.top()>= 97 && st.top()<=122)) && (st.top()!='[' )){
                    int n = st.top() - int('0'); 
                    if(x==0){
                        num=n;
                        x=1;
                    }
                    else{
                        x=x*10;
                        num=n*x + num;
                    }
                    
                    st.pop(); 
                }
                if(!st.empty()) {
                    while(num){
                        for(auto i: temp) 
                            st.push(i);
                        num--;
                    }
                }
                else{
                    
                    while(num){
                        res+=temp;
                        num--;
                    }
                }
                
            }
            else{
                st.push(s[i]);
            }
            
            i++;
        } 
        string p="";
        while(!st.empty()){
            p=st.top()+p;
            st.pop();
        }
        res+=p;
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends