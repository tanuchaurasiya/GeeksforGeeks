class Solution {
  public:
  static bool customComparison(string a, string b)
  {
      return (a + b) > (b + a);
  }
    string findLargest(vector<int> &arr) {
        int n=arr.size();
        vector<string> arrString(n);
        for(int i=0;i<n;i++)
        {
            arrString[i]= to_string(arr[i]);
        }
        
        sort(arrString.begin(), arrString.end(), customComparison);
        
        string finalString="";
        int i=0;
        while(i<n && arrString[i]=="0") i++;
        if(i==n) return "0";
        while(i<n) {finalString+=arrString[i]; i++;}
        return finalString;
    }
};