class Solution {
  public:
    int maxOnes(vector<int>& a) {
        int ones = 0;
        int curr = 0;
        int maxi = 0;
        int n=a.size();
        for(int i=0;i<n;i++){
          if(a[i] == 0){
              curr++;
              maxi = max(maxi,curr);
          }
          else{
              ones++;
              curr--;
              if(curr<0)
                curr = 0;
          }
        }
        
        
        return maxi+ones;
        
    }
};

