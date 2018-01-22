class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // map => { oldNode, newNode }
        map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return traverse(map, node);
    }
    
    UndirectedGraphNode* traverse(map<UndirectedGraphNode*, UndirectedGraphNode*>& map, UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (map.count(node)) return map[node];
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        map[node] = copy;
        for (auto neighbor : node->neighbors) {
            UndirectedGraphNode* neighborCopy = traverse(map, neighbor);
            (copy->neighbors).push_back(neighborCopy);
        }
        return copy;
    }
};
