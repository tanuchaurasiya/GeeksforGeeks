class Solution {
  public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }


int countBalanced(vector<string>& arr) {
    int n = arr.size();
    unordered_map<int, int> balanceFreq;
    balanceFreq[0] = 1; // empty prefix

    int res = 0;
    int prefixBalance = 0;

    for (int i = 0; i < n; ++i) {
        auto s=arr[i];
        for (char ch : s) {
            if (isVowel(ch)) prefixBalance++;
            else prefixBalance--;
        }
        res += balanceFreq[prefixBalance];

        balanceFreq[prefixBalance]++;
    }
    return res;
}


};