class Solution {
  public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int k) {
        int i=0;
        int j=0;
        int n=arr1.size();
        int m = arr2.size();
        k--;
        while(k && i<n && j<m){
            if(arr1[i]>arr2[j]){
                j++;
                k--;
            }
            else if(arr1[i]<arr2[j]){
                i++;
                k--;
            } 
            else{
                if(k>=2){
                    i++;
                    j++;
                    k-=2;
                }
                else{
                    i++;
                    k-=1;
                }
            }
        }
        if(k==0){
            if(i<n && j<m){
                if(arr1[i]>arr2[j]) return arr2[j];
                return arr1[i];
            }
            
            if(i<n) return arr1[i];
            return arr2[j];
        } 
        while(k && i<n) {
           i++;
           k--;
        }
        if(k==0) return arr1[i];
        
        while(k && j<m) {
           j++;
           k--;
        }
        if(k==0) return arr2[j];
        return -1;
        
    }
};