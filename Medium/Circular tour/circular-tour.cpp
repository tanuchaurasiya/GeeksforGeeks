//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
 
   int tour(petrolPump p[],int n){
        int start;
        
        int petrolSum=0;
        int distanceSum=0;
        
        for(int i=0;i<n;i++) petrolSum+=p[i].petrol;
        for(int i=0;i<n;i++) distanceSum+=p[i].distance; 
        
        if(petrolSum<distanceSum) return -1;
        
        int total=0;
        int res=0;
        for(int i=0;i<n;i++){
            total+=p[i].petrol-p[i].distance;
            if(total<0) {
                total=0;
                res=i+1;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends