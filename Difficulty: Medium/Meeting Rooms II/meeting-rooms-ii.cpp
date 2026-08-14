class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(),  start.end());
        sort(end.begin(),  end.end());
        
        int n=start.size();
        
        int i=1;
        int j=0;
        int res=1;
        int curr=1;
        
        while(i<n)
        {
            if(start[i]<end[j]) {
                curr++;
                i++;
            }
            else{
                curr--;
                j++;
            }
            res=max(res, curr);
        }
        return res;
    }
    
};
