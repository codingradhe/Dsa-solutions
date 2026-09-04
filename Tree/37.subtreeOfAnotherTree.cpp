// 572. Subtree of Another Tree
// Easy
// Given the roots of two binary trees root and
// subRoot, return true if there is a subtree of
// root with the same structure and node values of
// subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that 
// consists of a node in tree and all of this node'
// s descendants. The tree tree could also be 
// considered as a subtree of itself.


// leetcode link -->>  https://leetcode.com/problems/subtree-of-another-tree/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        if (!root || !subRoot)
            return false;

        if (root->val != subRoot->val)
            return false;

        return check(root->left, subRoot->left) &&
               check(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;

        if (!root)
            return false;

        if (check(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
