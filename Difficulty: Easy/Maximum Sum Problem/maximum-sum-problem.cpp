class Solution {
  public:
    int maxSum(int temp) {
        int x = int(temp/2);
        int y = int(temp/3);
        int z = int(temp/4);
        int sum=x+y+z;
        if(sum>temp){
            return  maxSum(x) + maxSum(y) + maxSum(z);
        }
        return temp;
    }
};