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
    int maxi = INT_MIN;
    int recc(TreeNode *root){
        if(!root) return 0;
        int l = max(recc(root->left),0);
        int r = max(recc(root->right), 0);
        int val = max(l,r) + root->val;
        maxi = max(l + r + root->val, maxi);
        return val;
    }
    int maxPathSum(TreeNode* root) {
        recc(root);
        return maxi;
    }
};