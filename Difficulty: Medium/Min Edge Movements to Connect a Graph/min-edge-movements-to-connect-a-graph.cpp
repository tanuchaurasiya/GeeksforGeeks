class Solution {
  public:
    int parent(int n, vector<int>&graph)
    {
        if(graph[n]<0) return n;
        int tmp=parent(graph[n], graph);
        graph[n]=tmp;
        return tmp;
    }
    
    void find_union(int n1, int n2, vector<int>&graph)
    {
        int p1=parent(n1, graph);
        int p2=parent(n2, graph);
        
        if(p1==p2) return;
        
        if(abs(graph[p1])>abs(graph[p2]))
        {
            graph[p1]+=graph[p2];
            graph[p1]=p2;
        }
        else{
            graph[p2]+=graph[p1];
            graph[p2]=p1;
        }
        return;
        
    }
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int ed=edges.size();
        
        if(n-1>ed) return -1;
        vector<int>graph(n,-1);
        for(auto e:edges)
        {
            find_union(e[0], e[1], graph);
        }
        
        int part=0;
        for(auto i:graph)
        {
            if(i<0) part++;
        }
        return part-1;
        
    }
};