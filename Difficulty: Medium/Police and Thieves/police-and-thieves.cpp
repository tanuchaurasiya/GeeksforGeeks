class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int p_idx=0;
        while(arr[p_idx]=='T') p_idx++;
        
        int t_idx=0;
        int n=arr.size();
        
        int ans=0;
        while(t_idx<n && p_idx<n)
        {
            if(arr[t_idx]=='T')
            {
                if(abs(t_idx-p_idx)<=k) 
                {
                    ans++;t_idx++;
                    p_idx++;
                    while(p_idx<n && arr[p_idx]!='P') p_idx++;
                }
                else{
                    if(t_idx>p_idx) 
                    {
                        p_idx++;
                        while(p_idx<n && arr[p_idx]!='P') p_idx++;
                    }
                    else t_idx++;
                }
                
                
            }
            else{
                t_idx++;
            }
            // cout<<"after "<<p_idx<<" "<<t_idx<<endl<<endl;
        }
        return ans;
        
    }
};