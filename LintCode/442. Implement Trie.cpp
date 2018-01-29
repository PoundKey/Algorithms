// 1. trie tree, also called prefix tree; starts with a root node
// 2. root node is empty, and we also branches that we can extend, each subsequent node could also be considered as "state"
// 3. everytime we reaches the next node though the branch, we gain the calibre of the branch
// 4. all the previous branches becomes assumption/premise, and we move on to next assumption or deduce the conclusion;
//    if the conclusion contradicts the assumption/premise, we exclude the assumption and invalidate the path.
// 5. I think this is also how our logic works, assumption + exclusion

class TrieNode {
    int counter;
    unordered_map<char, TrieNode*> branches;
public:
    TrieNode() : counter(0) {
        branches.clear();
    }
    
    void insert(const string& word, int index)
    {
        if (index >= word.size()) 
        {
            counter++;
            return;
        }
        char curChar = word[index];
        if (branches.count(curChar) == false)
        {
            branches[curChar] = new TrieNode();
        }
        return branches[curChar]->insert(word, index + 1);
    }

    void insert(string &word) {
        if (word.empty()) return;
        insert(word, 0);
    }
    
    bool search(const string& word, int index, bool matchWord = false)
    {
        if (index >= word.size()) 
        {
            return matchWord ? counter > 0 : true;
        }
        
        char curChar = word[index];
        if (branches.count(curChar))
        {
            return branches[curChar]->search(word, index + 1, matchWord);
        }
        return false;
    }

    bool search(string &word) {
        if (word.empty()) return true;
        return search(word, 0, true);
    }

    bool startsWith(string &prefix) {
        if (prefix.empty()) return true;
        return search(prefix, 0);
    }
};


class Trie {
private:
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}

    void insert(string &word) {
        root->insert(word);
    }

    bool search(string &word) {
        return root->search(word);
    }

    bool startsWith(string &prefix) {
        return root->startsWith(prefix);
    }
};
