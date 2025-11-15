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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int i=0; i<n; i++){
                TreeNode *node = q.front().first;
                int c = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, 2ll*c+1});
                if(node->right) q.push({node->right, 2ll*c+2});
                mini = min(mini, c);
                maxi = max(maxi, c);
            }
            ans = max(ans, maxi-mini+1);
        }
        return ans;
    }
};