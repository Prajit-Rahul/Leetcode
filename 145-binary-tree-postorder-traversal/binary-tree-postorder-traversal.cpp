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
    // void recc(TreeNode *root, vector<int> &ans){
    //     if(!root) return;
    //     if(root->left) recc(root->left, ans);
    //     if(root->right) recc(root->right, ans);
    //     ans.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     recc(root, ans);
    //     return ans;
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(!root) return ans;
    //     stack<TreeNode *> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode *node = st.top();
    //         st.pop();
    //         ans.push_back(node->val);
    //         if(node->left) st.push(node->left);
    //         if(node->right) st.push(node->right);
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *, int>> st;
        vector<int> in, post, pre;
        if(!root) return post;
        st.push({root,1});
        while(!st.empty()){
            TreeNode *node = st.top().first;
            int num = st.top().second;
            st.pop();
            if(num == 1){
                pre.push_back(node->val);
                num++;
                st.push({node, num});
                if(node->left) st.push({node->left, 1});
            }
            else if(num == 2){
                in.push_back(node->val);
                num++;
                st.push({node, num});
                if(node->right) st.push({node->right, 1});
            }
            else{
                post.push_back(node->val);
            }
        }
        return post;
    }
};