// 98. Validate Binary Search Tree
// Given the root of a binary tree, determine
// if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes 
// with keys strictly less than the node's key.
// The right subtree of a node contains only nodes
// with keys strictly greater than the node's key.
// Both the left and right subtrees must also be 
// binary search trees.
// Input: root = [2,1,3]
// Output: true
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// leetcode link -->>   https://leetcode.com/problems/validate-binary-search-tree/description/?utm_source=chatgpt.com
class Solution {
public:
    bool check(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return check(root->left, low, root->val) &&
               check(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
