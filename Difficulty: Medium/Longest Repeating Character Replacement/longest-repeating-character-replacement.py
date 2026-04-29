from collections import Counter
class Solution:
    def longestSubstr(self, s, k):
        right,left,maxL,n=0,0,0,len(s)
        d=Counter()
        while(right<n):
            d[s[right]] += 1
            #print(len(d))
            curr = right - left +1
            highfreq = d.most_common(1)
            #print(highfreq)
            if curr- highfreq[0][1] > k:
                ch = s[left]
                d[ch]-=1
                left+=1
                if d[ch]==0:
                    d.pop(ch)
            # print(d)
            #d[s[right]] +=1
            #curr = right - left +1
            maxL = max(maxL,right-left+1)
            #print(curr)
            right +=1
        
        return maxL