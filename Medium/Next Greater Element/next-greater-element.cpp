//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        stack<long long> s;
        unordered_map<long,long> rightGreater;
        for(int i = n-1; i>=0 ; i--){
            if(s.empty()){
                s.push(nums[i]);
                nums[i]=-1;
            }
            else{
                while(!s.empty()){
                    long val = s.top();
                    if(nums[i]>=val)
                        s.pop();
                    else{
                        s.push(nums[i]);
                        nums[i] = val;
                        break;
                    }
                }
                if(s.empty()){
                    s.push(nums[i]);
                    nums[i] = -1;
                }
            }
        }
        return nums;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends