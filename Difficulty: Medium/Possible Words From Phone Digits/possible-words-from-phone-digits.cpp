//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<char>> v{{},{},{'a','b','c'}, {'d','e','f'}, {'g', 'h', 'i'},{'j','k','l'}, {'m','n','o'},{'p','q','r','s'}, {'t','u','v'},{'w','x','y','z'}};

    vector<string> res;
    int n;
    void help(int i, string temp, int digits[]){
        if(i>=n) {
            res.push_back(temp);
            return;
        }
        int idx=digits[i];
        for(auto x:v[idx]){
            help(i+1, temp+x, digits);
        }
    }
   
    vector<string> possibleWords(int a[], int N)
    {
        n=N;
        if(n==0) return {};
        res.clear();
        help(0, "",a);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends