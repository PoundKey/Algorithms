// Thoughts: 
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return DFS(node, map);
    }
    UndirectedGraphNode* DFS(UndirectedGraphNode* node, 
                             unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map) {
        if (!node) return NULL;
        if (map.count(node)) return map[node];
        
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        map[node] = copy;
        
        for (int i = 0; i < node->neighbors.size(); i++) {
            copy->neighbors.push_back(DFS((node->neighbors)[i], map));
        }
        return copy;
    }
};
