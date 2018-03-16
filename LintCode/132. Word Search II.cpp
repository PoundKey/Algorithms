// 1. classical backtracking, keep in mind that all the parameters, e.g, row, col, pos, visited
//    are implying that pos - 1 has succeeded and now we are dealing with pos, row, col and visited.
// 2. use trie tree to delete some branches
class TrieNode
{
public:
    /// brief constructor
    TrieNode() : counter(0) 
    {
        branches.clear();
    }
    /// Insert a string to a TrieNode
    void Insert(const string& word, int index = 0)
    {
        if (index == word.size())
        {
            ++counter;
            return;
        }
        char curChar = word[index];
        if (branches.count(curChar) == false)
        {
            branches[curChar] = new TrieNode();
        }
        return branches[curChar]->Insert(word, index + 1);
    }
    
    bool Search(const string& word, int matchWord = false, int index = 0) const
    {
        if (index == word.size())
        {
            return matchWord ? counter > 0 : true;
        }
        char curChar = word[index];
        if (branches.count(curChar) == false) return false;
        return branches.at(curChar)->Search(word, matchWord, index + 1);
    }
    /// brief destructor
    virtual ~TrieNode() {}
private:
    unordered_map<char, TrieNode*> branches;
    int counter;
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        vector<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return res;
        int m = board.size(), n = board[0].size();
        TrieNode trie;
        string sol;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (auto iter = words.begin(); iter != words.end(); ++iter)
        {
            trie.Insert(*iter);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Search(board, words, res, sol, i, j, visited, trie);
            }
        }
        return res;
    }
    
    void Search(
        const vector<vector<char>> &board, 
        const vector<string> &words, 
        vector<string>& res, 
        string& sol,
        int row,
        int col,
        vector<vector<bool>>& visited,
        const TrieNode& trieNode)
        {
            if (trieNode.Search(sol, true) && 
                find(res.begin(), res.end(), sol) == res.end())
            {
                res.push_back(sol);
            }
            if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || 
                visited[row][col] || trieNode.Search(sol) == false)
            {
                return;
            }
            visited[row][col] = true;
            sol += board[row][col];
            Search(board, words, res, sol, row + 1, col, visited, trieNode);
            Search(board, words, res, sol, row - 1, col, visited, trieNode);
            Search(board, words, res, sol, row, col + 1, visited, trieNode);
            Search(board, words, res, sol, row, col - 1, visited, trieNode);
            sol.pop_back();
            visited[row][col] = false;
        }
};
