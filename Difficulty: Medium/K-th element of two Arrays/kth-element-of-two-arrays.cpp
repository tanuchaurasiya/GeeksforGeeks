class Solution {
  public:
    int kthElement(vector<int> &arr1, vector<int> &arr2, int k) {
int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1>n2){
            return kthElement(arr2, arr1, k);
        }
        int low=max(0,k-n2);
        int high=min(n1,k);
        int midIdx=k;
        while(low<=high)
        {

            int mid1 = (low+high)/2;
            int mid2 = midIdx-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
            
            if(mid1>0){
                l1=arr1[mid1-1];
            }
            
            if(mid2>0){
                l2=arr2[mid2-1];
            }
            
            if(mid1<n1){
                r1=arr1[mid1];
            }
            
            if(mid2<n2){
                r2=arr2[mid2];
            }
            
            if(l1>r2){
                high=mid1-1;
            }
            
            else if(l2>r1){
                low=mid1+1;
            }
            
            else{
                
                return double(max(l1,l2));
            }
            
        }
        return 0;
        
    }
};