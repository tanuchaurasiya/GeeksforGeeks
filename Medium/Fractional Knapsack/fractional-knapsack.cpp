//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double maxValue = 0;
        vector<pair<double,pair<int,int>>>ans;
        for(int i = 0 ; i < n ; ++i){
            int v = arr[i].value;
            int w = arr[i].weight;
            ans.push_back({double(v*1.0/w*1.0),{v,w}});
        }
        sort(ans.begin(),ans.end(),greater<pair<double,pair<int,int>>>());
        for(int i = 0 ; i < n ; ++i){
            if(W>=ans[i].second.second){
                maxValue+=ans[i].second.first;
                W-=ans[i].second.second;
            }
            else{
            maxValue = maxValue + ((W/(double)ans[i].second.second))*ans[i].second.first;
            break;
            }
        }
        return maxValue;
    }
        
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends