// 530. Minimum Absolute Difference in BST
// Easy
// Given the root of a Binary Search Tree (BST),
//   return the minimum absolute difference between
// the values of any two different nodes in the tree.
//  leetcode link ->>  https://leetcode.com/problems/minimum-absolute-difference-in-bst/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    int diff = INT_MAX;
    TreeNode *prev = NULL;
    void dfs(TreeNode *root) {
        if (root->left) dfs(root->left);
        if (prev) diff = min(diff, abs(prev->val - root->val));
        prev = root;
        if (root->right) dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return diff;
    }
};
