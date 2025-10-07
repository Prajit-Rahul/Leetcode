/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool tree(TreeNode* p, TreeNode *q){
        if(!p || !q) return p==q;
        return (p->val == q->val) && tree(p->left, q->left) && tree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans;
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val) ans = tree(root, subRoot);
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        return l || r || ans;
    }
};