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
    void recc(TreeNode *root, vector<int> &ans){
        if(!root) return;
        if(root->left) recc(root->left, ans);
        if(root->right) recc(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        recc(root, ans);
        return ans;
    }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode *> st;
    //     st.push(node);
    //     while(!st.empty()){
    //         TreeNode *node = st.top();
    //         st.pop();
    //         if(root->right) st.push(root->right);
    //         if(root->left) st.push(root->left);
    //     }
    //     return ans;
    // }
};