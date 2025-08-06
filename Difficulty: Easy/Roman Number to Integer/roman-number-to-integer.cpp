class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> mp = {{'I',1}, {'V', 5}, {'X', 10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        int i=0;
        int n=s.length();
        int res=0;
        while(i<n){
            if(s[i]=='I'){
                if(i+1<n && s[i+1]=='V'){
                    res+=4;
                    i++;
                }

                else if(i+1<n && s[i+1]=='X'){
                    res+=9;
                    i++;
                }
                else{
                    res+=mp[s[i]];
                }
            }

            else if(s[i]=='X'){
                if(i+1<n && s[i+1]=='L'){
                    res+=40;
                    i++;
                }

                else if(i+1<n && s[i+1]=='C'){
                    res+=90;
                    i++;
                }
                else{
                    res+=mp[s[i]];
                }
            }

            else if(s[i]=='C'){
                if(i+1<n && s[i+1]=='D'){
                    res+=400;
                    i++;
                }

                else if(i+1<n && s[i+1]=='M'){
                    res+=900;
                    i++;
                }
                else{
                    res+=mp[s[i]];
                }
            }

            else{
                res+=mp[s[i]];
            }

            i++;
        }

        return res;
    }
};