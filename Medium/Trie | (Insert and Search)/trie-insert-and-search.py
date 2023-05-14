#User function Template for python3

"""
class TrieNode: 
      
    def __init__(self): 
        self.children = [None]*26
  
        # isEndOfWord is True if node represent the end of the word 
        self.isEndOfWord = False
"""
#Function to insert string into TRIE.
def insert(root,word):
    temp=root
    n=len(word)
    for i in range(n):
        idx=ord(word[i])-97
        if temp.children[idx]==None:
            temp.children[idx]=TrieNode() 
        temp=temp.children[idx] 
    temp.isEndOfWord=1
    #code here

#Function to use TRIE data structure and search the given string.
def search(root, word):
    temp=root
    n=len(word) 
    for i in range(n):
        idx=ord(word[i])-97
        if temp.children[idx]==None:
            return 0
        temp=temp.children[idx]  
    return temp.isEndOfWord;
    #code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
class TrieNode: 
      
    def __init__(self): 
        self.children = [None]*26
  
        # isEndOfWord is True if node represent the end of the word 
        self.isEndOfWord = False
  
class Trie: 
      
    # Trie data structure class 
    def __init__(self): 
        self.root =TrieNode()
        
#use only 'a' through 'z' and lower case
def charToIndex(ch):
    return ord(ch)-ord('a')

if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        n=int(input())
        arr=input().strip().split()
        strs=input()
        
        t=Trie()
        
        for s in arr:
            insert(t.root,s)
        
        if search(t.root,strs):
            print(1)
        else:
            print(0)
# } Driver Code Ends