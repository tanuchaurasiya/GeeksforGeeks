class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        int count=end-start+1;
        int curr=0;
        for(int ele:arr){
            if(ele>=start && ele<=end){
                curr++;
            }
        }
        if(curr==count) return true;
        return false;
    }
};
