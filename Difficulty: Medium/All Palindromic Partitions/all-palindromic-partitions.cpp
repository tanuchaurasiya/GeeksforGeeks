class Solution {
  public:
    bool IsPalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void Solve(string& s,int idx,int n,vector<vector<string>> &ans, vector<string> &PossibleSolution){
        if(idx>=n){
            ans.push_back(PossibleSolution);
            return;
        }
        
        string tempstr = "";
        
        for(int i = idx; i<n;i++){
            
            tempstr.push_back(s[i]);
            
            if(!IsPalindrome(tempstr)){
                continue;
            }
            
            PossibleSolution.push_back(tempstr);
            Solve(s,i+1,n,ans,PossibleSolution);
            PossibleSolution.pop_back();
        }
    }
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string> PossibleSolution;
        
        Solve(s,0,s.length(),ans,PossibleSolution);
        
        return ans;
    }
};