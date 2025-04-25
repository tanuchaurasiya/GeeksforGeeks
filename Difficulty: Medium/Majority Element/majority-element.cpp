//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        // code here
        int size=nums.size();
        int count =0 ;
        int ele; 
        
        for(int i=0;i<size;i++){
            if(count==0){
                ele=nums[i];
                count++;
            }
            
            else if(nums[i] == ele) 
                count++; 
            else
                count--;
        } 
        
       int res=0;
        for(int i=0;i<size;i++){ 
            if(ele==nums[i])
                res+=1;
        }
        
        if(res>int(size)/2)
            return ele;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends