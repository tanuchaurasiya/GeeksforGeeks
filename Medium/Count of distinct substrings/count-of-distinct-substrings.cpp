//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends



struct node 
{
    node *children[26];
    
    
};

/*You are required to complete this method */
int countDistinctSubstring(string word)
{
    node* root=new node();
    int n=word.size();
    // cout<<n;
    int res=0;
    for(int i=0;i<n;i++)
    {
        node *temp=root;
        for (int j=i;j<n;j++)
        {
            int idx=int(word[j])-97;
            if (!temp->children[idx]) {
              res += 1;
              temp->children[idx] = new node();
            }

            temp = temp->children[idx];
        }
    }
    return res + 1;
}