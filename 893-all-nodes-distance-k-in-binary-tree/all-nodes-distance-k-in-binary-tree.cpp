/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_update(TreeNode* root, unordered_map<TreeNode *, TreeNode *> &parent){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push({target});
        unordered_map<TreeNode *, TreeNode *> parent;
        parent_update(root, parent);
        unordered_map<TreeNode *, bool> visited;
        int count = 0;
        if(k == 0) return {target->val}; 
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
            TreeNode *node = q.front();
            q.pop();
            if(visited[node]) continue;
            visited[node] = true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(parent.find(node) != parent.end()) q.push(parent[node]);
            }
            count++;
            if(count == k) break;
        }
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(visited[node]) continue;
            ans.push_back(node->val);
        }
        return ans;
    }
};