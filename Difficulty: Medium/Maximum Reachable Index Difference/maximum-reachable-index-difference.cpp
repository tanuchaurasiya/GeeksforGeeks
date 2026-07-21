class Solution {
  public:
    int maxIndexDifference(string &s) {
        vector<int> maxReach(26,-1);
        int n=s.size();
        int res=-1;
        for(int i=n-1;i>=0;i--)
        {
            int curr = s[i]-'a';
            int next = curr+1;
            
            int currReach;
            if(next!=26 && maxReach[next]!=-1) currReach=maxReach[next];
            else currReach = i;
            
            maxReach[curr]=max(maxReach[curr],currReach);

            if(s[i]=='a') res=max(res, currReach-i);
        }
        return res;
    }
};
