class Solution:
    def topoSort(self, V, adj):
        # Code here
        # print(adj)
        graph={} 
        for i in range(V):
            graph[i]=0
        queue=[]
        for i in range(V):
            for x in adj[i]:
                graph[x]+=1 
        for i in range(V):
            if graph[i]==0:
                queue.append(i) 
        # print(queue) 
        res=[]
        while queue:
            x=queue.pop(0)
            res.append(x)
            for child in adj[x]:
                graph[child]-=1
                if graph[child]==0:
                    queue.append(child)
        # print(res)        
        return res




#{ 
 # Driver Code Starts
# Driver Program

import sys
sys.setrecursionlimit(10**6)
        
def check(graph, N, res):
    if N!=len(res):
        return False
    map=[0]*N
    for i in range(N):
        map[res[i]]=i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        e,N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]
        
        for i in range(e):
            u,v=map(int,input().split())
            adj[u].append(v)
            
        ob = Solution()
        
        res = ob.topoSort(N, adj)
        
        if check(adj, N, res):
            print(1)
        else:
            print(0)
# Contributed By: Harshit Sidhwa

# } Driver Code Ends