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
    void recc(vector<int> &ans, TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        if(root->left) recc(ans, root->left);
        if(root->right) recc(ans, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        recc(ans, root);
        return ans;
    }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<Node *> st;
    //     TreeNode *temp = root;
    //     while(temp || st.empty()){
    //         st.push(temp->val);
            
    //     }
    // }
};