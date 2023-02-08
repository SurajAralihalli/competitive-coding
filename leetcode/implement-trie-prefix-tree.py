# Author: Suraj Aralihalli
# Url: https://leetcode.com/problems/implement-trie-prefix-tree/
# Date: 21st November, 2021
# Tags: trie, prefix-tree


# Approach 2
class TrieNode:
    children = None
    isWord = None
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isValid = False

class Trie:
    root = None
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            node = node.children[c]
        node.isWord = True

    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            if c in node.children:
                node = node.children[c]
            else:
                return False
        if node.isWord:
            return True
        else:
            return False
    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            if c in node.children:
                node = node.children[c]
            else:
                return False
        return True
    
# Approach 1    
class Node:
    def __init__(self):
        self.children = {}
        self.isWord = False;

class Trie:

    def __init__(self):
        self.root = Node()
        
    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            if(node.children.get(c)!=None):
                node = node.children[c]
            else:
                node.children[c] = Node()
                node = node.children[c]
        node.isWord = True
            

    def search(self, word: str) -> bool:
        node = self.root
        for c in word:
            if(node.children.get(c)!=None):
                node = node.children[c]
            else:
                return False
        return node.isWord
        

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            if(node.children.get(c)!=None):
                node = node.children[c]
            else:
                return False
        return True
