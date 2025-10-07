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
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(!root) return 0;
    //     int maxi1 = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
    //     int maxi = max(height(root->left)+height(root->right), maxi1);
    //     return maxi;
    // }
    // int height(TreeNode* root){
    //     if(!root) return 0;
    //     int maxi = 1 + max(height(root->left), height(root->right));
    //     return maxi;
    // }
    int maxi = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return maxi;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh =  height(root->right);
        int h = 1 + max(lh, rh);
        maxi = max(lh+rh, maxi);
        return h;
    }
};