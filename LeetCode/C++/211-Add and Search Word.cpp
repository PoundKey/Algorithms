class TrieNode
{
public:
    // 《我最闪亮》：我旅途的开场，我沿路的徽章
    int count;
    unordered_map<char, TrieNode*> path;
    
    TrieNode() : count(0)
    {
        
    }
    
    void insert(const string& word)
    {
        TrieNode* node = this;
        for (char c : word)
        {
            auto& path = node->path;
            if (!path.count(c))
            {
                path[c] = new TrieNode();
            }
            node = path[c];
        }
        node->count++;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool searchHelper(string word, TrieNode* root)
    {
        if (word.empty() && root)
        {
            return root->count > 0;
        }
        
        char c = word.front();
        word = word.substr(1); // rest of the word
        if (c == '.')
        {
            for (auto& node : root->path)
            {
                if (searchHelper(word, node.second))
                {
                    return true;
                }
            }
        }
        else
        {   
            if ((root->path).count(c))
            {
                return searchHelper(word, (root->path)[c]);
            }  
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
