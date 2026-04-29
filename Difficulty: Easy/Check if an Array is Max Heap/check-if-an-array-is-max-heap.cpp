class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n/2; i++)
         {
            // To satisfy the max heap condition, parent node must have high value then child nodes, check for that, if it's not satisfied return false.
             if((2*i+1 < n && arr[i] < arr[2*i+1]) || (2*i+2 < n && arr[i] < arr[2*i+2]) )
               return false;
         }
       // If all the parent nodes have higher value  than children nodes return true
         return true;  
        
    }
};
