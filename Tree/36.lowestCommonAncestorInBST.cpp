// 235. Lowest Common Ancestor of a Binary Search Tree
// Medium
// Given a binary search tree (BST), find the lowest 
// common ancestor (LCA) node of two given nodes in 
// the BST.

// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two
// nodes p and q as the lowest node in T that has 
// both p and q as descendants (where we allow a node
// to be a descendant of itself).”
// leetcode link of this problem -->> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/?utm_source=chatgpt.com
  class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode* ans;
        int pv = p->val,qv = q->val;
        while(root){
            int x = root->val;
            if(x > pv  && x > qv) root = root->left;
            else if(x < pv  && x < qv) root = root->right;
            else {
                ans = root;
                break;
            }
        }
        return ans;
    }
};
