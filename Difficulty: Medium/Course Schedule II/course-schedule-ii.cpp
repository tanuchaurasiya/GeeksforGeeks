class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &p) {
        vector<vector<int>> graph(n);
        unordered_map<int,int> mp;
        for(int i=0;i<p.size();i++){
            mp[p[i][0]]++;
            graph[p[i][1]].push_back(p[i][0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(mp[i]==0) q.push(i);
        }
        vector<int> res;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto child:graph[node]){
                mp[child]--;
                if(mp[child]==0) q.push(child);
            }
        }
        if(res.size()==n) return res;
        return {};
        
    }
};