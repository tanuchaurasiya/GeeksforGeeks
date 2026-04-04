#User function Template for python3

class Solution:
    def graycode(self,n):
        def help(n):
            if n==1:
                return ["0","1"]  
            else:
                temp=help(n-1) 
                l=len(temp)
                ans = [] 
                for i in range(l):
                    ans.append("0"+temp[i])
                for i in range(l-1,-1,-1):
                    ans.append("1"+temp[i])
            return ans
        
        ret=help(n) 
        return ret
        
        


