class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int hold = -arr[0], cash = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            hold = max(hold, cash - arr[i]);
            cash = max(cash, hold + arr[i] - k);
        }
        return cash;
    }
};