// 1022. Sum of Root To Leaf Binary Numbers
// Easy
// You are given the root of a binary tree where each node has
// a value 0 or 1. Each root-to-leaf path represents a binary
// number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this
//   could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented
// by the path from the root to that leaf. Return the sum of 
// these numbers.

// The test cases are generated so that the answer fits in a 
// 32-bits integer.
// leetcode link -->>  https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=problem-list-v2&envId=tree
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        curr = curr * 2 + node->val; // append this bit

        if (!node->left && !node->right) // leaf
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }
};
