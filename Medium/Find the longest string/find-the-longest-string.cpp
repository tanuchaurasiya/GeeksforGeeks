//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++



struct node 
{
    node *children[26];
    int countprefix=0;
    int countend=0;
    
};
struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() < second.size();
    }
};




class Solution
{
public:


    
int insert(string &word, int n, node* root){
        node *temp=root;
        int res=1;
        for (int i = 0; i < n; i++) {
          int idx = int(word[i]) - 97;
          if (i != n - 1 && (!temp->children[idx]) || (temp!=root && temp->countend==0)) {
            res = 0;
          }

          if (!temp->children[idx])
            temp->children[idx] = new node();
          temp = temp->children[idx];
        }

        temp->countend += 1;

        return res;
}
    
string longestString(vector<string> &a)
    {
    compare c;
    node* root=new node();
    sort(a.begin(), a.end(), c);
    int max=-100001;
    string res="";
    for(auto i:a) {
        int n=i.size();
        if (insert(i, n,root)) {
            if (max == n && lexicographical_compare(&i,&i+n,&res,&res+n))
                res = i;
            else if (max < n) {
                max = n;
                res = i;
              }
        }
    
    }
    return res;
    }
};













//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends