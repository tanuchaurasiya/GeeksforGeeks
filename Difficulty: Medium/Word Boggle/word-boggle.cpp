//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    struct Node {
        struct Node *children[26];
        bool isLeaf;
    };

    Node* root;
    unordered_set<string> resSet;
    int m,n;
    void insert(string word){
        Node *temp=root;
        int s= word.size();
        for(int i=0;i<s;i++){
            char c = (char) tolower(word[i]);
            int idx=c-'a';
            if (!temp->children[idx])
                temp->children[idx]=new Node();
            temp=temp->children[idx] ;           
        }
        temp->isLeaf=1;
    }

    bool isValid(int i, int j, vector<vector<int>>& visited){
        if(i<0 || j<0|| i>=m || j>=n || visited[i][j]) return false;
        return true;
    }
    void search(int i, int j, Node* temp, string s, vector<vector<char>>& board, vector<vector<int>>& visited)
    {
        visited[i][j] = 1;
        char c = (char) tolower(board[i][j]);
        int idx = c - 'a';
        if (temp->children[idx]==NULL) {
            visited[i][j] = 0;
            return ;
        }
        if(temp->children[idx]->isLeaf) {
            resSet.insert(s+board[i][j]);
        }

        if(isValid(i+1, j, visited)) search(i+1, j, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i, j+1, visited)) search(i, j+1, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i-1, j, visited)) search(i-1, j, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i, j-1, visited)) search(i, j-1, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i-1, j-1, visited)) search(i-1, j-1, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i+1, j+1, visited)) search(i+1, j+1, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i+1, j-1, visited)) search(i+1, j-1, temp->children[idx], s+board[i][j], board, visited);
        if(isValid(i-1, j+1, visited)) search(i-1, j+1, temp->children[idx], s+board[i][j], board, visited);
        
        visited[i][j] = 0;

    }
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& words) {
        root = new Node();
        m = board.size();
        n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(auto w:words){
            insert(w);
        }

        resSet.clear();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                search(i,j,root, "",board, visited);
            }
        }
        vector<string> resVec;
        for(auto i:resSet) resVec.push_back(i);
        return resVec; 
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends