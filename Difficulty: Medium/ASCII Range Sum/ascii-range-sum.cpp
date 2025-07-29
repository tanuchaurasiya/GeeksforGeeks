class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n=s.length();
        vector<int> psum(n);
        psum[0]=int(s[0]);
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+int(s[i]);
        }
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(first[idx]==-1){
                first[idx]=i;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            int idx=s[i]-'a';
            if(last[idx]==-1){
                last[idx]=i;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<26;i++){
            int f=first[i];
            int l=last[i];
            if(l>f+1) {
                // cout<<f<<" "<<psum[f]<<" "<<l<<" "<<psum[l]<<endl;
                ans.push_back(psum[l]-psum[f]-('a'+i));
            }
        }
        return ans;
        
    }
};