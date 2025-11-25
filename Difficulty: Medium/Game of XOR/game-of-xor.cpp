class Solution {
  public:
    int subarrayXor(vector<int>& A) {
        int N=A.size();
        if(N%2==0) return 0;
        int ans=0;
        for(int i=0;i<N;i+=2)
        {
            ans^=A[i];
        }
        return ans;
    }
};