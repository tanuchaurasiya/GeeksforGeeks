//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    string fun(int i,int j,vector<vector<vector<int>>>&M)
{
    if(i==j)return"" ;
    if(i+1==j)
    {
        string s="";
        s+=char(i+'A');
        return s;
    }

 return "("+fun(M[i][j][1],M[i][j][2],M)+fun(M[i][j][2],M[i][j][3],M)+")";
}


    string matrixChainOrder(int arr[], int n){

    vector<vector<vector<int>>>M(n,vector<vector<int>>(n,vector<int>(4,0)));
    int i,j;
    
    for(int k=2;k<n;k++)
    {
        i=0;
        j=k;
        while(j<n)
        {
            M[i][j][0]=INT_MAX;
            for(int l=i+1;l<j;l++)
            {
             if(M[i][j][0]>M[i][l][0]+M[l][j][0]+arr[i]*arr[l]*arr[j])
             {
                M[i][j][0]=M[i][l][0]+M[l][j][0]+arr[i]*arr[l]*arr[j];
                M[i][j][1]=i;
                M[i][j][2]=l;
                M[i][j][3]=j;
             }
            // M[i][j]=min(M[i][j],M[i][l]+M[l][j]+arr[i]*arr[l]*arr[j]);
            }
            j++;
            i++;
        }
    }
    return fun(0,n-1,M);

    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends