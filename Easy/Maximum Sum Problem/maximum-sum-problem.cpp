//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            queue<int>q;
            q.push(n);
            int res=0;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                int x = int(temp/2);
                int y = int(temp/3);
                int z = int(temp/4);
                int sum=x+y+z;
                if(sum>temp){
                    q.push(x);
                    q.push(y);
                    q.push(z);
                }
                else{
                    res+=temp;
                }
            }
            return res;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends