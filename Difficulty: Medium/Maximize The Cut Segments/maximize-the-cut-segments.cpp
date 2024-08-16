//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> tab(n,0);
        if(n>=x)
            tab[n-x]=1;
        if(n>=y)
            tab[n-y]=1;
        if(n>=z)
            tab[n-z]=1;
        for(int i=n-1;i>0;i--){
            if(!tab[i])
                continue;
            if(i>=x)
                tab[i-x]=max(tab[i-x],tab[i]+1);
            
            if(i>=y)
                tab[i-y]=max(tab[i-y],tab[i]+1);
                
            if(i>=z)
                tab[i-z]=max(tab[i-z],tab[i]+1);
        }
        return tab[0];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends