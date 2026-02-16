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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int xPar = 0, xHeight = 0, yHeight = 0, yPar = 0;
        bool xFind =false, yFind = false;
        while(!q.empty()){
            TreeNode *node = q.front().first;
            int ht = q.front().second;
            q.pop();
            if((node->left && node->left->val == x) || (node->right && node->right->val == x)){
                xHeight = ht+1;
                xPar = node->val;
                xFind = true;
            }
            if((node->left && node->left->val == y) || (node->right && node->right->val == y)){
                yHeight = ht+1;
                yPar = node->val;
                yFind = true;
            }
            if(xFind && yFind) break;
            if(node->left) q.push({node->left, ht+1});
            if(node->right) q.push({node->right, ht+1});
        }
        if(xHeight == yHeight && xPar != yPar) return true;
        return false;
    }
};