class TrieNode {
public:
    // Initialize your data structure here.
    int count;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() : count(0) 
    {
        children.clear();
    }
    
    void insert(string word) 
    {
        TrieNode* node = this;
        for (char c : word)
        {
            if (!(node->children.count(c)))
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->count++;
    }
    
    TrieNode* find(string word) 
    {
        TrieNode* node = this;
        for (char c : word)
        {
            if (!(node->children.count(c)))
            {
                return NULL;
            }
            node = node->children[c];
        }
        
        return node;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() : root(new TrieNode())
    {

    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        root->insert(word);
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        TrieNode* node = root->find(word);
        return (node != NULL && node->count > 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        TrieNode* node = root->find(prefix);
        return node != NULL;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
