

class Solution{   
public:
    int isSumString(string S){
         int n = S.length();
         for(int i =1;i< n;i++){
             for(int j =1;i + j <n;j++){
                 if(helper(S,0,i,j,n)) return true;
             }
         }
         return false;
    }
    bool helper(string s,int start,int len1,int len2,int n){
        string s1 = s.substr(start,len1);
        string s2 = s.substr(start + len1,len2);
        string s3 = add_str(s1 , s2);
        int newlen = s3.length();
        if(len1 + len2 + newlen + start > n) return false;
        if(s.substr(start + len1 + len2,newlen) == s3){
            if(len1 + len2 + newlen + start == n) return true;
            return helper(s,start + len1,len2,newlen,n);
        }
        return false;
    }
    string add_str(string num1, string num2) {
    string result;
    int carry = 0;

    if (num1.length() < num2.length())
        return add_str(num2, num1);

    int i = num1.length() - 1, j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;

        result += to_string(sum);
    }

    reverse(result.begin(), result.end());
    return result;
}
};





