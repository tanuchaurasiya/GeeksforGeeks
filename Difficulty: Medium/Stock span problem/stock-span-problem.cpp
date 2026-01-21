class Solution {
  public:
    vector<int> calculateSpan(vector<int>& price) {
        int n=price.size();
        vector<int> leftGreater(n,-1);
       
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                leftGreater[i] = -1;
                s.push({0, price[i]});
            }
            else{
                while(!s.empty()){
                    int idx = s.top().first;
                    int val = s.top().second;
                    if(val<=price[i])
                        s.pop();
                    else{
                        leftGreater[i] = idx;
                        s.push({i,price[i]});
                        break;
                    }
                }
                
                if(s.empty()) 
                {
                    leftGreater[i] = -1;
                    s.push({i,price[i]});
                }
            }
        }
        
        for(auto i=0;i<n;i++){
            leftGreater[i] = i-leftGreater[i];
        }
        return leftGreater;
        
    }
};