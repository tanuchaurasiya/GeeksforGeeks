#User function Template for python3

#User function Template for python3

class Solution:
    def prefixMatchCheck(self,str1,str2):
        if len(str1)<len(str2):
            return False
        for i in range(len(str2)):
            if(str2[i]!=str1[i]):
                return False
        return True
    
    def CamelCase(self,N,Dictionary,Pattern) :
        temp=[]
        ans=[] 
        flag=0;
        for i in range(N):
            t=""
            for j in range(len(Dictionary[i])):
                if(Dictionary[i][j]>='A' and Dictionary[i][j]<='Z'):
                    t=t+Dictionary[i][j]
            temp.append(t)
       
        for i in range(len(temp)):
            if (self.prefixMatchCheck(temp[i],Pattern)):
                ans.append(Dictionary[i])
                flag=1
       
        if(flag==0):
            return ["-1"]
        return ans
    





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        Dictionary=list(map(str,input().split()))
        Pattern=input()
        ob=Solution()
        ans=ob.CamelCase(N,Dictionary,Pattern)
        ans.sort()
        for i in ans:
            print(i,end=" ")
        print()    
# } Driver Code Ends