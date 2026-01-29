class Solution {
  public:
    string firstNonRepeating(string &A) {
        vector<int> v(26,0);
		    string res="";
		    for(int i=0;i<A.length();i++){
		        int idx = A[i]-'a';
		        if(v[idx]==0) {
		            v[idx]=i+1;
		        }
		        else{
		            v[idx]=-1;
		        }
		        int minn=INT_MAX;
		        for(int j=0;j<26;j++){
		            if(v[j]>0) minn=min(minn, v[j]);
		        }
		        
		        if(minn==INT_MAX) res+="#";
		        else res+=A[minn-1];
		    }
		    return res;
        
    }
};