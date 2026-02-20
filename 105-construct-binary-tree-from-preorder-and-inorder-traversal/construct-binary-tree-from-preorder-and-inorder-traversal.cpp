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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        TreeNode *root = buildTree(preorder, 0, n-1, 0, n-1, mp);
        return root;
    }
    TreeNode *buildTree(vector<int>& preorder, int ps, int pe, int is, int ie, unordered_map<int, int> &mp){
        if(ie<is || pe<ps) return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int inRoot = mp[preorder[ps]];
        int numLeft = inRoot - is;
        root->left = buildTree(preorder, ps+1, ps+numLeft, is, inRoot-1, mp);
        root->right = buildTree(preorder, ps+numLeft+1, pe, inRoot+1, ie, mp);
        return root;
    }
};