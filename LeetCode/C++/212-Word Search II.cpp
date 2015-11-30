// Thoughts: 
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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        TrieNode* trie = new TrieNode();
        for (int i = 0; i < words.size(); i++) trie->insert(words[i]);
        unordered_set<string> set;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                DFS(board, "", trie, visited, set, i, j);
        }
        for (auto& elem : set) res.push_back(elem);
        sort(res.begin(), res.end());
        return res;
    }
    
    void DFS(vector<vector<char>>& board, string word, TrieNode* trie, vector<vector<bool>>& visited, unordered_set<string>& res, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col]) return;
        
        word += board[row][col];
        if (!trie->startsWith(word)) return;
        if (trie->search(word)) res.insert(word);
        
        visited[row][col] = true;
        DFS(board, word, trie, visited, res, row + 1, col);
        DFS(board, word, trie, visited, res, row - 1, col);
        DFS(board, word, trie, visited, res, row, col + 1);
        DFS(board, word, trie, visited, res, row, col - 1);
        visited[row][col] = false;
    }
};