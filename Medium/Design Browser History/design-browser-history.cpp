//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class BrowserHistory {
public:
    vector<string> st;
    int pointer; 
    int length;
    BrowserHistory(string homepage) { 
        st.push_back(homepage); 
        pointer=1; 
        length=1;
    }
    
    void visit(string url) {  
        if(length>pointer){
            // cout<<length<<" "<<pointer<<endl;
            int c = length-pointer;
            int cn=c;
            while(c){
                st.pop_back();
                c--;
            }
            length=length-cn;
        }
        st.push_back(url);
        length++;
        pointer=length;
        
    }
    
    string back(int steps) { 
        if(pointer-steps<=0) {
            pointer=1;
            return st[0];
        }
        else{
            pointer-=steps;
            return st[pointer-1];
        }
        
        
    }
    
    string forward(int steps) {
        if(pointer+steps>length) {
            pointer=length;
            return st[length-1];
        }
        else{
            pointer+=steps;
            return st[pointer-1];
        }
        
    }
};





//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends