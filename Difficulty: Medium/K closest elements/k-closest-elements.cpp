// User function template for C++

struct Compare
{
    bool operator() (pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.first>p2.first)
            return true; 
        if(p1.first==p2.first){
            if(p1.second<p2.second) return true;
            return false;
        }
        return false;
    }
};

class Solution {
  public:
  
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(int i=0;i<n;i++){
            if(arr[i]!=x) pq.push({abs(x-arr[i]), arr[i]});
        }
        vector<int> res;
        while(k>0){
           res.push_back(pq.top().second);
           k--;
           pq.pop();
       }
        
        // reverse(res.begin(), res.end());
        return res;
    }
};

