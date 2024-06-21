//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int compareFractions(string fraction1, string fraction2) {
        // finding postion of '/' in both fractions
        int pos1 = fraction1.find('/');
        int pos2 = fraction2.find('/');
        
        // extracting numerators and denominators and converting them into integer
        int num1 = stoi(fraction1.substr(0, pos1));
        int den1 = stoi(fraction1.substr(pos1+1));
        
        int num2 = stoi(fraction2.substr(0, pos2));
        int den2 = stoi(fraction2.substr(pos2+1));
        
        // comparing fractions using cross multiplication
        if (num1 * den2 < num2 * den1) {
            return -1;      // fraction 2 is greater
        }
        else if (num1 * den2 > num2 * den1) {
            return 1;       // fraction 1 is greater
        }
        else {
            return 0;       // both fractions are equal
        }
    } 
    
    string compareFrac(string str) {
        // Code here
        if (str.size() <= 0) {
            return "";
        }
        
        // using stringstream to split given string from the space
        stringstream ss(str);
        string word;
        
       // we'll use vector v to store extracted words from string
        vector<string> v;
        
        while (ss >> word) {
            if (word[word.size() - 1] == ',') {
                word.pop_back();
            }
            
            v.push_back(word);
        }
        
        int ans = compareFractions(v[0], v[1]);
        
        if (ans == 1) {
            return v[0];
        }
        else if (ans == -1) {
            return v[1];
        }
        else {
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends