//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> qt;
        qt.push({startWord,1});
        unordered_set<string>dict(wordList.begin(),wordList.end());
        dict.erase(startWord);
        while(!qt.empty()){
            string word=qt.front().first;
            int steps=qt.front().second;
            if(word==targetWord) return steps;
            qt.pop();
            for(int i=0;i<word.size();i++){
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(dict.find(word)!=dict.end()){
                        qt.push({word,steps+1});
                        //erase krna is neccessary as nii kroge toh diktt hoga kyunki 
                        //a-z kaa wo use krrhe toh agrr wo mil chuka toh future mei waps
                        //same word bna kee hm step naa bdhae....
                        //kyunki agrr wo mil gya toh wo push hoga queue mei aur usko jbb
                        //pop krnege wo doobara milega aur loop chlte reh jaaega
                        //aur step bdhte reh jaaega
                        dict.erase(word);
                    }
                    //ye isiliye kiye maan lo a-z kaa combination use krr liye on the first
                    //character and uske baad bhi nii mila hmko apne dict mei uska mtlb hai 
                    //usko orignal bna do ab next character ko change krke dekho 
                    
                    word[i]=orignal;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends