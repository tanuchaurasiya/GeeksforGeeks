class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int five=0;
        int ten=0;
        int twenty=0;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==5) five++;
            else if(arr[i]==10)
            {
                if(five==0) return false;
                ten++;
                five--;
            }
            else{
                if(five==0 || (ten==0 && five<3)) return false;
                if(ten>0 && five>0) {
                    ten--;
                    five--;
                }
                else {
                    five-=3;
                }
                twenty++;
            }
        }
        return true;
    }
};