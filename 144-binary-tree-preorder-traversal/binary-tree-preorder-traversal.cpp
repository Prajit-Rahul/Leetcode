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
    // void recc(vector<int> &ans, TreeNode* root){
    //     if(!root) return;
    //     ans.push_back(root->val);
    //     if(root->left) recc(ans, root->left);
    //     if(root->right) recc(ans, root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     recc(ans, root);
    //     return ans;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }
};