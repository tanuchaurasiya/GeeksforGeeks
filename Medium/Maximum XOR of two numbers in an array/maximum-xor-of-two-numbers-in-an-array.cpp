//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++



struct trienode
{
  trienode *arr[2];  
};
class Solution {
public:
    void insert(int num,trienode* root){
        trienode *temp=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if( ! temp->arr[bit])
                temp->arr[bit] = new trienode(); 
            temp=temp->arr[bit]; 
        }
    } 
    
    int findmax(int num, trienode* root){ 
        trienode *temp=root;
        int res=0;
        for(int i=31;i>=0;i--){
            int bit = num>>i & 1; 
            if(bit==0){
                if(temp->arr[1]){
                    res+=pow(2,i);
                    temp=temp->arr[1];
                } 
                else{
                    temp=temp->arr[0];
                }
            }
            if(bit==1){
                if(temp->arr[0]){
                    res+=pow(2,i);
                    temp=temp->arr[0];
                } 
                else{
                    temp=temp->arr[1];
                }
            } 
        }
        return res;
        
    }
    
    int max_xor(int arr[] , int n) {
        trienode *root=new trienode(); 
        for(int i=0;i<n;i++) 
            insert(arr[i],root); 
        int maxx=0; 
        for(int i=0;i<n;i++) 
            maxx=max(maxx,findmax(arr[i],root));
        return maxx;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends