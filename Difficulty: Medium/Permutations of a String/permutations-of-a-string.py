#User function Template for python3

class Solution:
    def findPermutation(self, S):
        # Code here
        def help(idx,n,temp,res):
            if idx>=n:
                res.add("".join(temp)) 
                
            for i in range(idx,n):
                temp[i],temp[idx]=temp[idx],temp[i] 
                help(idx+1,n,temp,res)
                temp[i],temp[idx]=temp[idx],temp[i] 
        res=set()
        temp=[x for x in S] 
        # print(temp)
        n=len(S)
        help(0,n,temp,res)
        res=list(res)
        res.sort()
        # print(res)
        return res






#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        S = input()
        ob = Solution()
        ans = ob.findPermutation(S)
        ans.sort()
        for i in ans:
            print(i, end=" ")
        print()
        print("~")

# } Driver Code Ends