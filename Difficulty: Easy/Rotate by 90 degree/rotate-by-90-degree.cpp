//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
//   1 2 3       1 4 7        // 0 1 -> 1 0 (swap)
//   4 5 6    =  2 5 8       // 0 2 -> 2 0
//   7 8 9       3 6 9      // 1 2 -> 2 1
    void rotateby90(vector<vector<int> >& mat) {
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                if(i!=j){
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }
        
        int i=0;
        int j=n-1;
        while(i<j){
            swap(mat[i], mat[j]);
            i++;
            j--;
        }
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends