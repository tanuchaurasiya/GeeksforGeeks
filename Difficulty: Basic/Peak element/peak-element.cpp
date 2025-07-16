class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        if(n==1) return 0;
       if(arr[0]>=arr[1]) return 0;
       if(arr[n-1]>=arr[n-2]) return n-1;
       
       int i=1;
       while(i<n-1){
           if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]) return i;
           i++;
       }
       return -1;
    }
};