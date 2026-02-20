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
    // bool isSame(TreeNode *root, TreeNode *subRoot){
    //     if(!root && !subRoot) return true;
    //     if(!root || !subRoot) return false;
    //     return root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    // }
    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if(!root || !subRoot) return false;
    //     return (root->val == subRoot->val && isSame(root, subRoot))|| isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    // }
    string seralize(TreeNode *node){
        if(!node) return "N";
        return "("+to_string(node->val)+"," + seralize(node->left) + "," + seralize(node->right)+")";
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootSerial = seralize(root);
        string subRootSerial = seralize(subRoot);
        return rootSerial.find(subRootSerial) != string::npos;
    }
};