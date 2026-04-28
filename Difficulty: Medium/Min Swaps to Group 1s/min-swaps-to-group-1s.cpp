class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int c=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==1) c++;
        }
        if(c==0) return -1;
        n = arr.size();
        
        
        int zero=0;
        int i=0;
        while(i<c){
            if(arr[i]==0) zero++;
            i++;
        }
        
        int res=zero;
        while(i<n){
            if(arr[i-c]==0) zero--;
            if(arr[i]==0) zero++;
            res=min(res, zero);
            i++;
        }
        return res;
    }
};