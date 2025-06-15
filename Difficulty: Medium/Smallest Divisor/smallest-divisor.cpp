class Solution {
  public:
    int help(int &mid, vector<int>& arr)
    {
        int sum=0;
        for(auto i:arr)
        {
            if(i%mid==0) sum+=int(i/mid);
            else sum= sum+int(i/mid)+1;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int l=1;
        int h=*max_element(arr.begin(), arr.end());
        while(l<=h)
        {
            int mid=(l+h)/2;
            int x=help(mid,arr);
            // cout<<"mid="<<mid<<" x="<<x<<endl;
            if(x<=k) h=mid-1;
            else l=mid+1;
        }
        return l;
        
    }
};
