// 226. Invert Binary Tree

// Given the root of a binary tree, invert the tree
// , and return its root.

// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// leetcode link -->>   https://leetcode.com/problems/invert-binary-tree/?envType=problem-list-v2&envId=tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
