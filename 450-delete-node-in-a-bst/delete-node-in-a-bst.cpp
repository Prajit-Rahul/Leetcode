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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *node = root;
        if(!root) return root;
        if(root->val == key) return helper(root);
        while(node){
            if(node->val < key){
                if(node->right && node->right->val == key){
                    node->right = helper(node->right);
                    break;
                }
                else{
                    node = node->right;
                }
            }
            else{
                if(node->left && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
        }
        return root;
    }
    TreeNode *helper(TreeNode* root){
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = right(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode *right(TreeNode* root){
        if(root->right)
            return right(root->right);
        return root;
    }
};