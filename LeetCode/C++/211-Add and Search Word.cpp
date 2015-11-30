// Thoughts: Try to 'confirm' word[index] with current trieNode and its children.
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

class WordDictionary {
private: 
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    
    void addWord(string word) {
        root->insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    bool searchHelper(string& word, int index, TrieNode* root) {
        if (index == word.size()) return root->count > 0;
        char c = word[index];
        if (c == '.') {
            for (auto& node : root->children) {
                if (node && searchHelper(word, index + 1, node)) return true;
            }
        } else if ((root->children)[c - 'a']) {
            return searchHelper(word, index + 1, (root->children)[c - 'a']);
        } 
        return false;
    }
};
