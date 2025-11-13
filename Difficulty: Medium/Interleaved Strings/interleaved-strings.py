class Solution:
    def isInterleave(self, s1, s2, s3):
        memo = {}
        
        def dfs(i,j,k):
            if i == len(s2):
                return s1[j:] == s3[k:]
            if j == len(s1):
                return s2[i:] == s3[k:]
            
            ans = False
            if (i,j) in memo:
                return memo[(i,j)]
            else:
                ans = (s2[i] == s3[k] and dfs(i + 1,j,k + 1)) or \
                        (s1[j] == s3[k] and dfs(i,j + 1,k + 1))
                memo[(i,j)] = ans
            
            return memo[(i,j)]
        
        if len(s1) + len(s2) != len(s3):
            return False
        else:
            return dfs(0,0,0)