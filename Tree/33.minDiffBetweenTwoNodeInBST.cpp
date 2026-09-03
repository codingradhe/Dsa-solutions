// 783. Minimum Distance Between BST Nodes
// Given the root of a Binary Search Tree (BST), 
//   return the minimum difference between the
// values of any two different nodes in the tree.
// leetcode link -->>   https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
  class Solution {
public:
    void helper(TreeNode* root, int& minDiff, int& prevVal) {
        if (root == nullptr)
            return;
        helper(root -> left, minDiff, prevVal);
        if (prevVal != -1) {
            minDiff = min(minDiff, root -> val - prevVal);
        }
        prevVal = root -> val;
        helper(root -> right, minDiff, prevVal);
        
    }
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevVal = -1;
        helper(root, minDiff, prevVal);
        return minDiff;
    }
};
