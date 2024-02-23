//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int temp)
        {
            int x = int(temp/2);
            int y = int(temp/3);
            int z = int(temp/4);
            int sum=x+y+z;
            if(sum>temp){
                return + maxSum(x) + maxSum(y) + maxSum(z);
            }
            else{
                return temp;
            }
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