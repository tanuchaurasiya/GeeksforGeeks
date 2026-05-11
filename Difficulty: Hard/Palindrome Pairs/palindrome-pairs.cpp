class Solution {
  public:
  bool isPal(string &w, int st, int end) {
        while (st < end) {
            if (w[st] != w[end]) return false;
            st++;
            end--;
        }
        return true;
    }

    bool palindromePair(vector<string>& words) {
        
        int N = words.size();
        vector<vector<int>> output;

        unordered_map<string, int> lookup;

        for (int i = 0; i < N; i++) {
            lookup[words[i]] = i;
        }

        for (int i = 0; i < N; i++) {

            string w = words[i];
            if (w == "") {
                for (int j = 0; j < N; j++) {
                    if (i != j && isPal(words[j], 0, words[j].size() - 1)) {
                        return true;
                    }
                }
                continue;
            }
            string bw = w;
            reverse(bw.begin(), bw.end());

            if (lookup.count(bw) && lookup[bw] != i) {
                return true;
            }

            for (int k = 1; k < w.size(); k++) {

                // Prefix palindrome
                if (isPal(w, 0, k - 1)) {

                    string suffix = w.substr(k);
                    reverse(suffix.begin(), suffix.end());

                    if (lookup.count(suffix)) {
                       return true;
                    }
                }

                // Suffix palindrome
                if (isPal(w, k, w.size() - 1)) {

                    string prefix = w.substr(0, k);
                    reverse(prefix.begin(), prefix.end());

                    if (lookup.count(prefix)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
   
};