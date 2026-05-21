class Solution {
  public:
    bool isBitSet(int n) {
        if(n==0) return false;
        while(n)
        {
            if(n%2==0) return false;
            n=n/2;
        }
        return true;
        
    }
};