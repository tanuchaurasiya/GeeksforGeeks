class Solution:
    def kthMissing(self, arr, k):
        lo, hi = 0, len(arr)-1
        while lo <= hi:
            mid = (lo + hi) // 2
            missing = arr[mid] - (mid+1)
            if missing >= k: 
                hi = mid-1
            else: 
                lo = mid + 1
        m = arr[hi] - (hi+1)
        return arr[hi] + k-m
        