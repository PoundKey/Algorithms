// 1. most important part, we need to record the count of characters' appearance in the string (map?)
// 2. foreach item (character : count) in the map, wrap it using a node struct and push into a priority queue
//    2.1 important part for this step is overload the comparator, using m_counter and m_char
// 3. pop out each node from the priority queue, and convert back to origional string
// 
// Runtime Complexity: T(n) = O(nlogn), S(n) = O(n)

class Solution {
public:
    /**
     * @param str: the string that needs to be sorted
     * @return: sorted string
     */
    struct Node
    {
        char m_char;
        int m_count;
        
        Node()
        {  
        }
        
        Node(char in_char, int in_count) 
            : m_char(in_char), m_count(in_count)
        {    
        }
        
        bool operator() (const Node& n1, const Node& n2)
        {
            if (n1.m_count == n2.m_count)
            {
                return n1.m_char > n2.m_char;
            }
            return n1.m_count < n2.m_count;
        }
    };
    
    string Convert(const Node& node)
    {
        char c = node.m_char;
        int count = node.m_count;
        string res;
        for (int i = 0; i < count; i++)
        {
            res += c;
        }
        return res;
    }
    
    string stringSort(string &str) {
        if (str.empty()) return "";
        unordered_map<char, int> store;
        for (int i = 0; i < str.size(); i++)
        {
            store[str[i]] += 1;
        }
        
        priority_queue<Node, vector<Node>, Node> queue;
        for (const auto& item : store)
        {
            Node node(item.first, item.second);
            queue.push(node);
        }
        
        string res;
        while (!queue.empty())
        {
            Node node = queue.top();
            queue.pop();
            res += Convert(node);
        }
        return res;
    }
};
