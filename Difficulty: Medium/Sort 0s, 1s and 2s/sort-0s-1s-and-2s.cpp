class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        int m=l;
        
        while(m<=h){
            if(arr[m]==0){
                swap(arr[m], arr[l]);
                m++;
                l++;
            }
            else if(arr[m]==2){
                swap(arr[m], arr[h]);
                h--;
            }
            else{
                m++;
            }
        }
        return;
    }
};
