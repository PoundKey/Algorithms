#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    int count;
    TrieNode* children[26];
    
    TrieNode() : count(0) {
        for (auto &c : children) c = NULL;
    }
    
    void insert(string word, int index = 0) {
        if (index == word.size()) {
            this->count++;
            return;
        }
        int pos = word[index] - 'a';
        if (!children[pos]) {
            children[pos] = new TrieNode();
        }
        children[pos]->insert(word, index + 1);
    }
    
    TrieNode* find(string word, int index = 0) {
        if (index == word.size()) return this;
        int pos = word[index] - 'a';
        if (!children[pos]) return NULL;
        return children[pos]->find(word, index + 1);
    }
    
    bool search(string word) {
        TrieNode* node = find(word, 0);
        return (node != NULL && node->count > 0);
    }

    bool startsWith(string prefix) {
        TrieNode* node = find(prefix, 0);
        return node != NULL;
    }
};