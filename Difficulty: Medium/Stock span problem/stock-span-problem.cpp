//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> leftGreater(n,-1);
       
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                leftGreater[i] = -1;
                s.push({0, price[i]});
            }
            else{
                while(!s.empty()){
                    int idx = s.top().first;
                    int val = s.top().second;
                    if(val<=price[i])
                        s.pop();
                    else{
                        leftGreater[i] = idx;
                        s.push({i,price[i]});
                        break;
                    }
                }
                
                if(s.empty()) 
                {
                    leftGreater[i] = -1;
                    s.push({i,price[i]});
                }
            }
        }
        
        for(auto i=0;i<n;i++){
            leftGreater[i] = i-leftGreater[i];
        }
        return leftGreater;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends