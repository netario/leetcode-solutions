/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private: 
    unordered_map<int, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        if (hash.count(node->label) > 0) return hash[node->label];
        UndirectedGraphNode* u = hash[node->label] = new UndirectedGraphNode(node->label);
        for (auto& neighbor : node->neighbors) 
            u->neighbors.push_back(cloneGraph(neighbor));
        return u;
    }
};