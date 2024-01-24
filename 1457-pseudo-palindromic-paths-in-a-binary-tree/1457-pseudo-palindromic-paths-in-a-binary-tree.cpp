class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* root, int mask) {
        if (root == nullptr) {
            return 0;
        }
        mask ^= 1 << root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return (mask & (mask - 1)) == 0 ? 1 : 0;
        }
        return dfs(root->left, mask) + dfs(root->right, mask);
    }
};