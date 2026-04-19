// User function Template for C++
class Solution {
  public:
    int powerof2(int n){
        if(n == 1) return true;
        else if(n % 2 != 0 or n == 0) return false;
        return powerof2(n/2);
    }
        
    string lexicographicallySmallest(string str, int k) {
        // code here
        int n=str.length();
        if(powerof2(n)) k=k/2;
        else k*=2;
        
        // cout<<"k="<<k<<endl;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) 
            {
                st.push(str[i]);
                continue;
            }
            
            if(st.top()>str[i])
            {
                
                while(!st.empty() && k && st.top()>str[i])
                {
                    // cout<<str[i]<<" "<<st.top()<<endl;
                    st.pop();
                    k--;
                }
            }
            st.push(str[i]);
        }
        if(st.empty()) return "-1";
        while(k && !st.empty()) {st.pop(); k--;};
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(res=="") return "-1";
        return res;
    }
};