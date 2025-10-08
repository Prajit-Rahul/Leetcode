/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &mp){
        Node *clone = new Node(node->val);
        mp[node] = clone;
        vector<Node *> neighbor;
        for(int i=0; i<node->neighbors.size(); i++){
            if(mp.find(node->neighbors[i]) != mp.end()){
                neighbor.push_back(mp[node->neighbors[i]]);
            }
            else{
                neighbor.push_back(dfs(node->neighbors[i], mp));
            }
        }
        clone->neighbors = neighbor; 
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(node->neighbors.size() == 0){
            Node *clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }
};