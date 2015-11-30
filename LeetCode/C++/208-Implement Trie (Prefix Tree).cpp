// Thoughts: For each trie node, use an array[26] to store all the possible child nodes.
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
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        root->insert(word);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root->find(word);
        return (node != NULL && node->count > 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root->find(prefix);
        return node != NULL;
    }

private:
    TrieNode* root;
};

// Thoughts: Use a hashmap to store char : TrieNode* pair
class TrieNode {
public:
    // Initialize your data structure here.
    int count;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() : count(0) {
        children.clear();
    }
    
    void insert(string word, int index = 0) {
        if (index == word.size()) {
            this->count++;
            return;
        }
        char c = word[index];
        if (!children.count(c)) {
            children[c] = new TrieNode();
        }
        children[c]->insert(word, index + 1);
    }
    
    TrieNode* find(string word, int index = 0) {
        if (index == word.size()) return this;
        char c = word[index];
        if (!children.count(c)) return NULL;
        return children[c]->find(word, index + 1);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        root->insert(word);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root->find(word);
        return (node != NULL && node->count > 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root->find(prefix);
        return node != NULL;
    }

private:
    TrieNode* root;
};
