// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/implement-trie-prefix-tree/
// Date: 21st November, 2021
// Tags: trie, prefix-tree

class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isWord = false;
        children = unordered_map<char, TrieNode*>();
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c: word) {
            if(node->children.find(c)==node->children.end()) {
                node->children[c] = new TrieNode();
                node = node->children[c];
            }
            else {
                node = node->children[c];
            }
        }
        node->isWord = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c: word) {
            if(node->children.find(c)==node->children.end()) {
                return false;
            }
            else {
                node = node->children[c];
            }
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c: prefix) {
            if(node->children.find(c)==node->children.end()) {
                return false;
            }
            else {
                node = node->children[c];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
