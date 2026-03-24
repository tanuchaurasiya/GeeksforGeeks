class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,int> dep;
        unordered_map<int,vector<int>> graph;
        
        for(auto x:pre)
        {
            dep[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(dep[i]==0)q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto child:graph[node])
            {
                dep[child]--;
                if(dep[child]==0) q.push(child);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dep[i]>0) return false;
        }
        return true;
    }
};