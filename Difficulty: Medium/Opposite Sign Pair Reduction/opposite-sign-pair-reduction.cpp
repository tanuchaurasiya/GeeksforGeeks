class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty()) {
                st.push(arr[i]);
                continue;
            }
            bool add=false;
            if((st.top()>0 && arr[i]>0) || (st.top()<0 && arr[i]<0)) {
                st.push(arr[i]);
                continue;
            }
            while(!st.empty())
            {
                int top=st.top();
                // cout<<top<<endl;
                if((top<0 && arr[i]>0) || (top>0 && arr[i]<0))
                {
                    if(abs(top)==abs(arr[i])) {add=false;st.pop();break;}
                    else if(abs(top)>abs(arr[i])) { add=false;break;}
                    else {st.pop(); add=true;}
                }
                else{
                    break;
                }
            }
            if(add) st.push(arr[i]);
            
            
        }
        n=st.size();
        vector<int> res(n);
        int i=n-1;
        while(!st.empty())
        {
            res[i]=st.top();
            i--;
            st.pop();
        }
        return res;
    }
};