class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vector<int> res;
        unordered_map<int,int> visited;
        int resXor=0;
        int i=0,j=0,k=0;
        
        int n1=a.size();
        int n2=b.size();
        int n3=c.size();
        
        while(i<n1 && j<n2 && k<n3)
        {
            int m1=a[i];
            int m2=b[j];
            int m3=c[k];
            
            if(m1==m2 && m2==m3) {
                i++;j++;k++; 
                // cout<<i<<" "<<j<<" "<<k<<endl;
                if(!visited[m1]) {res.push_back(m1); visited[m1]=1;}
                continue;
            }
            
            if(m1<=m2 && m1<=m3)
            {
                i++;
                if(m2==m3) continue;
                else if(m2<m3) j++;
                else k++;
            }
            else if(m2<=m1 && m2<=m3)
            {
                j++;
                if(m1==m3) continue;
                else if(m1<m3) i++;
                else k++;
            }
            else{
                k++;
                if(m1==m2) continue;
                else if(m1<m2) i++;
                else j++;
            }
        }
        return res;
    }
};