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
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == p || node == q) return node;
        TreeNode *l = (node->left)?dfs(node->left, p, q):NULL;
        TreeNode *r = (node->right)?dfs(node->right, p, q):NULL;
        if(l && r) return node;
        if(!l) return r;
        if(!r) return l;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};