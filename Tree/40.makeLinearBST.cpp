// 897. Increasing Order Search Tree
// Easy
// Given the root of a binary search tree, rearrange
// the tree in in-order so that the leftmost node
// in the tree is now the root of the tree, and
//   every node has no left child and only one right
// child.
 // leetcode link -->>   https://leetcode.com/problems/increasing-order-search-tree/?envType=problem-list-v2&envId=tree
  class Solution {
public:
    void maketree(TreeNode* root,TreeNode*&newroot){
        if(!root) return;
        maketree(root->left,newroot);
        TreeNode* x = new TreeNode(root->val);
        newroot->right = x;
        newroot = x;
        maketree(root->right,newroot);
        return;
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* newroot = new TreeNode(-1);
        TreeNode* mover = newroot;
        maketree(root,mover);
        return newroot->right;
    }
};
