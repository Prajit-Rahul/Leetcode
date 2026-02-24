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
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        vector<Node *> neighbors;
        for(auto &it: node->neighbors){
            if(mp.find(it) != mp.end()){
                neighbors.push_back(mp[it]);
            }
            else{
                neighbors.push_back(dfs(it, mp));
            }
        }
        newNode->neighbors = neighbors;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(node->neighbors.size() == 0){
            Node *temp = new Node(node->val);
            return temp;
        }
        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }
};