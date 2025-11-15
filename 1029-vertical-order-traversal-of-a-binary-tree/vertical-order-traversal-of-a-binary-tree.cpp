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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        unordered_map<int,vector<pair<int,int>>> mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0}, root});
        int mini = INT_MAX, maxi = INT_MIN;
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                TreeNode *node = q.front().second;
                auto [r,c] = q.front().first;
                mini = min(mini, c);
                maxi = max(maxi, c);
                q.pop();
                mp[c].push_back({r,node->val});
                if(node->left) q.push({{r+1,c-1}, node->left});
                if(node->right) q.push({{r+1,c+1}, node->right});
            }
        }
        for(int i=mini; i<=maxi;i++){
            sort(mp[i].begin(), mp[i].end());
            vector<int> temp;
            for(auto &it: mp[i]){
                temp.push_back(it.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};