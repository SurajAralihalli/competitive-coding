// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/word-search-ii/
// Date: 28th August, 2022
// Tags: trie, prefix-tree

class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isWord = False
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word:str):
        node = self.root
        for c in word:
            node = node.children[c]
        node.isWord = True

    def search(self, word:str) -> bool:
        node = self.root
        for c in word:
            node = node.children.get(c)
            if not node:
                return False
        return True
        
class Solution:
    def __init__(self):
        self.mat = None
        self.sol = []
        
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        
        for word in words:
            trie.insert(word)
            
        node = trie.root
        self.mat = board
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(node, i, j, "")
        
        return self.sol
        
    def dfs(self, node: TrieNode, i:int, j:int, path:""):
        
        if(node.isWord):
            self.sol.append(path)
            node.isWord = False
            
        if(i >= len(self.mat) or i < 0 or j >= len(self.mat[0]) or j < 0):
            return
        
        c = self.mat[i][j]
        if(node.children.get(c) == None):
            return
        else:
            nextNode = node.children.get(c)
            self.mat[i][j] = "#"
            self.dfs(nextNode, i+1, j, path+c)
            self.dfs(nextNode, i-1, j, path+c)
            self.dfs(nextNode, i, j+1, path+c)
            self.dfs(nextNode, i, j-1, path+c)
            self.mat[i][j] = c
            return
