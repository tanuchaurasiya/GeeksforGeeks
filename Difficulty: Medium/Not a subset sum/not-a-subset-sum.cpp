class Solution {
  public:
   
    int findSmallest(vector<int> &a) {
        sort(a.begin(),a.end());
        long long int res=1;
        for(int i=0;i<a.size() && a[i]<=res;i++)
            res+=a[i];
        return res;
    }
};