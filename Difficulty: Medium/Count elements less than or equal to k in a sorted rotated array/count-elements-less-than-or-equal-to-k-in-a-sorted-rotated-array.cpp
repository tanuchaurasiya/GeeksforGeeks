class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while (low < high) {
            int mid = low + (high - low) / 2;
    
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int count = 0;
        count += upper_bound(arr.begin(), arr.begin() + low, x) - arr.begin();
        count += upper_bound(arr.begin() + low, arr.end(), x) - (arr.begin() + low);

        return count;
        
    }
};