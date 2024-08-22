//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        unordered_map<char, int> mp;
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<N-1;i++){
            int j = i+1;
            int n1 = 0;
            int n2=0;
            while(dict[i][n1]!='\0' && dict[j][n2]!='\0'){
                if(dict[i][n1]!=dict[j][n2]){
                    mp[dict[j][n2]]++;
                    adj[dict[i][n1]].push_back(dict[j][n2]);
                    break;
                }
                
                n1++;
                n2++;
            }
        }
        
        queue<char> q;
        string res="";
        
        for(int i=0;i<k;i++){
            if(mp['a'+i]==0)  q.push('a'+i);
        }
       
        while(!q.empty()){
            char node = q.front();
            q.pop();
            res+=node;
            for(auto child:adj[node]){
                mp[child]--;
                if(mp[child]==0) 
                    q.push(child);
            }
        } 
        return res;
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends