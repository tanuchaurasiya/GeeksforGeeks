class Solution {
  public:
    int findPosition(int n) {
        int pos=0;
        int count=0;
        while(n)
        {
            if(n%2==1) {
                if(count) return -1;
                count++;
            }
            n=n/2;
            pos++;
        }
        return pos;
        
    }
};